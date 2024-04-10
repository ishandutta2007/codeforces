#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define gc getchar
#define fr first
#define sc second
using namespace std;
typedef pair<int,int>pii;
const int N=5010;
const int inf=1e9;
int a[N],nt[N],fr[N],v[N],l[N][N],r[N][N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)v[i]=0;
	rep(i,1,n){
		fr[i]=v[a[i]];
		v[a[i]]=i;
	}
	rep(i,1,n)v[i]=n+1;
	dep(i,n,1){
		nt[i]=v[a[i]];
		v[a[i]]=i;
	}
	rep(len,1,n-1)rep(i,1,n-len){int j=i+len;
		l[i][j]=l[i+1][j]+1;
		r[i][j]=r[i][j-1]+1;
		for(int k=nt[i];k<=j;k=nt[k]){
			int w=l[k][j];
			if(i+1<=k-1)w+=min(l[i+1][k-1],r[i+1][k-1])+1;
			if(w<l[i][j])l[i][j]=w;
		}
		for(int k=fr[j];k>=i;k=fr[k]){
			int w=r[i][k];
			if(k+1<=j-1)w+=min(l[k+1][j-1],r[k+1][j-1])+1;
			if(w<r[i][j])r[i][j]=w;
		}
	}
	printf("%d\n",min(l[1][n],r[1][n]));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}