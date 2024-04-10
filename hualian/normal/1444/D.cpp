#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
bool ppp;
const int N=1e3+10;
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
int T;
bitset<500010>f[1001];
int a[N],b[N];
vector<int>A;
vector<int>B;
bool pppp;
bool work(int *a,int n,vector<int>&A){
	f[0].reset();f[0][0]=1;
	int sum=0;rep(i,n)sum+=a[i];sum/=2;
	rep(i,n){
		f[i]=f[i-1]|(f[i-1]<<a[i]);
		if(f[i][sum]){
			int now=sum;
			Rof(j,i,1)if(now-a[j]>=0&&f[j-1][now-a[j]]){
				now-=a[j];a[j]=-a[j];
			}break;
		}
	}rep(i,n)A.push_back(a[i]);
	sum=0;rep(i,n)sum+=a[i];
	return sum==0;
}
struct node{int x,y;}sta[N];
inline int qua(node&a){return (a.y<0)<<1|(a.x>0)^(a.y>0);}
bool cmp(node&a,node&b){
	return qua(a)==qua(b)?(a.x*b.y-a.y*b.x>0):qua(a)<qua(b);
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	T=read();
	while(T--){
		int n,m,sum=0,f=0;
		n=read();rep(i,n)a[i]=read(),sum+=a[i];if(sum%2)f=1;sum=0;
		m=read();rep(i,m)b[i]=read(),sum+=b[i];if(sum%2)f=1;sum=0;
		f|=(n!=m);
		if(f){puts("No");continue;}
		A.clear();B.clear();
		if(!work(a,n,A)){puts("No");continue;}
		if(!work(b,m,B)){puts("No");continue;}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		rep(i,n)sta[i]=node{A[i-1],B[i-1]};
		sort(sta+1,sta+1+n,cmp);
//		for(int x:A)cout<<x<<" ";puts("");	
		For(i,2,n){
			if(qua(sta[i-1])<qua(sta[i]))continue;
			assert(qua(sta[i-1])==qua(sta[i]));
			assert(sta[i].x*sta[i-1].y-sta[i].y*sta[i-1].x<=0);
		}
		int x=0,y=0; 
		puts("Yes");
		rep(i,n){
			x+=sta[i].x;
			printf("%d %d\n",x,y);
			y+=sta[i].y;
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}