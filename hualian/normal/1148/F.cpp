#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
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
int a[N],s[N];
vector<int>A[70];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();int sum=0,S=0;
	rep(i,n)a[i]=read(),s[i]=read(),sum+=a[i];
	if(sum<0){rep(i,n)a[i]=-a[i];sum=-sum;}
	rep(i,n)Rof(j,61,0)if((s[i]>>j)&1){A[j].push_back(i);break;}
	For(k,0,61){
		int all=0;
		for(int to:A[k])all+=a[to];
		if(all>0){rep(i,n)if((s[i]>>k)&1)a[i]=-a[i];S|=1ll<<k;}
	}
	cout<<S<<endl;
	return 0;
}