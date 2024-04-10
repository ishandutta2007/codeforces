// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int i,j,k;
int n,x,y;
int f1[maxn],f2[maxn*2],f3[maxn*2],r;
int siz[maxn];
int w,ww,www;
int lll,b[maxn],cc[maxn];
long long tot1,tot2,num1,num2,ans;
void add(int x,int y){
	r++; f2[r]=y; f3[r]=f1[x]; f1[x]=r;
}
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void getw(int x,int fa){
	int i=f1[x],t=0;
	siz[x]=1;
	while(i!=0){
		if ((f2[i]!=fa)&&(f2[i]!=0)){
			getw(f2[i],x);
			siz[x]=siz[x]+siz[f2[i]];
			t=max(t,siz[f2[i]]);
		}
		i=f3[i];
	}
	t=max(t,www-siz[x]);
	if (ww>t){ ww=t; w=x; }
}
void dfs(int x,int fa,int w){
	int i=f1[x];
	if (w%2==1){
		tot1=tot1+w; num1++;
	}
	else{
		tot2=tot2+w; num2++;
	}
	while (i!=0){
		if ((f2[i]!=fa)&&(f2[i]!=0)){
			dfs(f2[i],x,w+1);
		}
		i=f3[i];
	}
}
void work(int x,int len){
	int i,t1,t2;
	www=len; ww=len; w=0; getw(x,0);
	long long tnum1=0,tnum2=0,ttot1=0,ttot2=0;
	i=f1[w];
	while (i!=0){
		if (f2[i]!=0){
			num1=0; num2=0; tot1=0; tot2=0;
			dfs(f2[i],w,1);
			ans=ans+(ttot2/2)*num2+(tot2/2)*tnum2;
			ans=ans+(ttot2/2)*num1+(((tot1-num1)/2)+num1)*tnum2;
			ans=ans+(tot2/2)*tnum1+(((ttot1-tnum1)/2)+tnum1)*num2;
			ans=ans+((ttot1-tnum1)/2)*num1+((tot1-num1)/2)*tnum1+num1*tnum1;
			ans=ans+(tot2/2)+((tot1-num1)/2)+num1;
			tnum1=tnum1+num1; tnum2=tnum2+num2;
			ttot1=ttot1+tot1; ttot2=ttot2+tot2;
		}
		i=f3[i];
	}
	i=f1[w]; t1=lll+1;
	while (i!=0){
		if (f2[i]!=0){ lll++; b[lll]=siz[f2[i]]; cc[lll]=f2[i]; }
		f2[i]=0; if (i%2==1) f2[i+1]=0; else f2[i-1]=0;
		i=f3[i];
	}
	t2=lll;
	for (i=t1;i<=t2;i++) work(cc[i],b[i]);
}
int main(){
	n=read();
	for (i=1;i<n;i++){
		x=read(); y=read();
		add(x,y); add(y,x);
	}
	work(1,n);
	printf("%I64d\n",ans);
	return 0;
}