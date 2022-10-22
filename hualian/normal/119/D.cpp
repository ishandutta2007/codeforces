#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e6+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,z[N],c[N];
char s[N],t[N];
char S[N];
void Z(char *s,int n,int *z) {
	rep(i,n)z[i]=0;
	z[1]=n;int l=0,r=0;
	For(i,2,n){
		if(i<=r)z[i]=min(z[i-l+1],r-i+1);
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1])++z[i];
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
}
void input(){
	char ch;
	while(1){
		ch=getchar();if(ch=='\n'||ch==EOF)break;
		s[++n]=ch;
	}s[n+1]='\0';
	while(1){
		ch=getchar();if(ch=='\n'||ch==EOF)break;
		t[++m]=ch;
	}t[m+1]='\0';
	return;
}
vector<int>had[N]; 
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	input();
	
	rep(i,n)S[i]=t[i],S[i+n]=s[i];
	Z(S,2*n,z);rotate(z+1,z+1+n,z+1+2*n);
	
	rep(i,n)S[i]=s[i],S[i+n]=t[i];reverse(S+1,S+1+n);
	Z(S,2*n,c);rotate(c+1,c+1+n,c+1+2*n);rep(i,n)c[i]=c[i]+i-1;
	
	rep(i,n)had[c[i]].push_back(i);
	
	if(n!=m){puts("-1 -1");return 0;}
	unsigned long long ha=0,hb=0;
	int mn=n+1,ans1=0,ans2=0; 
	for(int x:had[n])chmn(mn,x);
	rep(i,n-1){
		for(int x:had[n-i])chmn(mn,x);
		ha=ha*97+s[i]-'a'+1;
		hb=hb*97+t[n-i+1]-'a'+1;
		if(ha!=hb)break;
		if(mn<=z[i+1]+1)ans1=i,ans2=mn;
	}
	cout<<ans1-1<<" "<<ans1+ans2-1<<endl;
	return 0;
}
////////////