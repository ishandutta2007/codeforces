//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
typedef long double db;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=65,m=60;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
db p;
db a[maxn][maxn],b[maxn][maxn];
db A[maxn][maxn],B[maxn][maxn];
db f[maxn][maxn];
void init(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=a[i][j-1]*a[i-1][j-1];
			if(j==1)a[i][j]+=p;
			if(j==2)a[i][j]+=1-p;
			A[i][j]=a[i][j]*(1-a[i-1][j]);
			b[i][j]=b[i][j-1]*a[i-1][j-1];
			if(j==2)b[i][j]+=1;
			B[i][j]=b[i][j]*(1-a[i-1][j]);
		}
	}
	f[1][1]=1,f[1][2]=2;
	for(int i=2;i<=m;i++){
		db s1=0,s2=0;
		for(int j=2;j<=m;j++){
			s1+=f[i-1][j-1]*A[i-1][j-1];
			f[i][j]=j+s1/(1-a[i-1][j]);
		}
		for(int j=2;j<=m;j++)s2+=f[i-1][j]*B[i-1][j];
		f[i][1]=1+s2;
	}
	return ;
}
struct matrix{
	db x[maxn][maxn];
	void clear(){
		for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)x[i][j]=0;
		return ;
	}
	matrix operator *(matrix p)const{
		matrix res;res.clear();
		for(int i=0;i<=m;i++)
			for(int j=0;j<=m;j++)
				for(int k=0;k<=m;k++)
					res.x[i][k]+=x[i][j]*p.x[j][k];
		return res;
	}
};
matrix power(matrix x,int b){
	matrix res;res.clear();
	for(int i=0;i<=m;i++)res.x[i][i]=1;
	while(b){
		if(b&1)res=res*x;
		x=x*x;
		b>>=1;
	}
	return res;
}
db g[maxn];
int main(){
    int n;db res=0;
	n=read();p=1.0*read()/1e9;
	init();
	if(n<=m){
		for(int i=1;i<=m;i++)res+=f[n][i]*A[n][i];
		printf("%.10Lf\n",res);
		return 0;
	}
	matrix T;T.clear();
	T.x[0][0]=1;for(int i=1;i<=m;i++)T.x[0][i]=i;
	for(int j=2;j<=m;j++)T.x[j][1]=B[m][j];
	for(int j=1;j<=m;j++){
		for(int k=j+1;k<=m;k++){
			db sum=0;
			for(int i=1;i<k;i++)sum+=A[m][i];
			T.x[j][k]=A[m][j]/sum;
		}
	}
	T=power(T,n-m);
	f[m][0]=1;
	for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)g[i]+=T.x[j][i]*f[m][j];
	for(int i=1;i<=m;i++)res+=g[i]*A[m][i];
	printf("%.10Lf\n",res);
    return 0;
}