#include<bits/stdc++.h>
#define ull unsigned long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
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
int n;
ull h[N],p[N];
ull get(int pos,int len){return h[pos+len-1]-h[pos-1]*p[len];}
int lcp(int x,int y){
	int l=0,r=n-max(x,y)+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(get(x,mid)==get(y,mid))l=mid+1;
		else r=mid-1;
	}return l-1;
}
int lcs(int x,int y){
	int l=0,r=min(x,y);
	while(l<=r){
		int mid=(l+r)>>1;
		if(get(x-mid+1,mid)==get(y-mid+1,mid))l=mid+1;
		else r=mid-1; 
	}return l-1;
}
char s[N];
void rebuild(int k){
	int m=k,now=0;
	For(i,k+1,n){
		s[++m]=s[i];
		if(s[m]==s[m-k])now++;
		else now=0;
		if(now==k)m-=k,now=0;
	}n=m;
}
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	p[0]=1;rep(i,n)p[i]=p[i-1]*147744151;
	rep(i,n)h[i]=h[i-1]*p[1]+s[i];
	for(int k=1;k<=n;k++){
		int f=0;
		for(int i=2*k;i<=n;i+=k)
		if(lcp(i-k,i)+lcs(i-k,i)-1>=k){
			f=1;break;
		}if(!f)continue;
		rebuild(k);
		rep(i,n)h[i]=h[i-1]*p[1]+s[i];
	}
	rep(i,n)putchar(s[i]);
	return 0;
}