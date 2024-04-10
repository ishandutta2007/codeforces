#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
inline int Read(){
	char c;do c=getchar();while(c!='0' && c!='1');return c-'0';
}
const int maxn=210;
int i,j,k,n,m,T,a[maxn][maxn];
struct node{
	int x,y;
};
struct A{
	node s[3];
}ans[maxn*maxn*2];int cnt;
void work(int X0,int Y0,int X1,int Y1,int X2,int Y2){
	ans[++cnt]=(A){(node){X0,Y0},(node){X1,Y1},(node){X2,Y2}};
	a[X0][Y0]^=1;a[X1][Y1]^=1;a[X2][Y2]^=1;
}
void OUT(node a){
	printf("%d %d ",a.x,a.y);
}
void out(){
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		OUT(ans[i].s[0]),OUT(ans[i].s[1]),OUT(ans[i].s[2]),puts("");
}
int main(){
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n>>m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				a[i][j]=Read();
		if(n&1){
			for(i=1;i<=m;i++)
				if(a[n][i]==1){
					if(i!=1)work(n,i,n-1,i-1,n-1,i);
					else work(n,i,n-1,i,n-1,i+1);
				}
			n--;
		}
		if(m&1){
			for(i=1;i<=n;i++)
				if(a[i][m]==1){
					if(i!=1)work(i,m,i-1,m-1,i,m-1);
					else work(i,m,i,m-1,i+1,m-1);
				}
			m--;
		}
		for(i=1;i<=n;i+=2)
			for(j=1;j<=m;j+=2){
//				cerr<<"OK!"<<' '<<i<<' '<<j<<' '<<a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]<<endl;
				while(a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]!=0){
					if(a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]==1){
						int X[4],Y[4],s=0;
						for(int h1=i;h1<=i+1;h1++)
						for(int h2=j;h2<=j+1;h2++)
						if(a[h1][h2]==1)X[s]=h1,Y[s++]=h2;
						for(int h1=i;h1<=i+1;h1++)
						for(int h2=j;h2<=j+1;h2++)
						if(a[h1][h2]==0)X[s]=h1,Y[s++]=h2;
						work(X[0],Y[0],X[1],Y[1],X[2],Y[2]);
					}else
					if(a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]==2){
						int X[4],Y[4],s=0;
						for(int h1=i;h1<=i+1;h1++)
						for(int h2=j;h2<=j+1;h2++)
						if(a[h1][h2]==0)X[s]=h1,Y[s++]=h2;
						for(int h1=i;h1<=i+1;h1++)
						for(int h2=j;h2<=j+1;h2++)
						if(a[h1][h2]==1)X[s]=h1,Y[s++]=h2;
						work(X[0],Y[0],X[1],Y[1],X[2],Y[2]);
					}else{
						int X[4],Y[4],s=0;
						for(int h1=i;h1<=i+1;h1++)
						for(int h2=j;h2<=j+1;h2++)
						if(a[h1][h2]==1)X[s]=h1,Y[s++]=h2;
						work(X[0],Y[0],X[1],Y[1],X[2],Y[2]);
					}
				}
			}
		out();
	}
	return 0;
}