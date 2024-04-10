#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,k;
int a[N],b[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();
	while(T-->0){
		n=read(),k=read();
		rep(i,n)a[i]=b[i]=read();
		sort(b+1,b+1+n);
		int j=1;
		int ansl=0,ansr=1e9;
		rep(i,n){
			while((j-i+1)-(n-(j-i+1))<k&&j<n)j++;
			if((j-i+1)-(n-(j-i+1))>=k)if(b[j]-b[i]<ansr-ansl)
				ansr=b[j],ansl=b[i];
		}
		rep(i,n)if(a[i]>=ansl&&a[i]<=ansr)a[i]=1;else a[i]=-1;
		int last=0,cnt=1;
		rep(i,n)a[i]+=a[i-1];
		printf("%d %d\n",ansl,ansr);
		rep(i,n){
			if(cnt==k)break;
			if(a[i]==cnt)printf("%d %d\n",last+1,i),last=i,cnt++;
		}
		printf("%d %d\n",last+1,n);
	}
	return 0;
}