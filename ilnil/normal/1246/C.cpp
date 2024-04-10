#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define add(x,y)(x=(y+x)%mo)
using namespace std;
const int N=2005,mo=1e9+7,mo2=998244353;
int n,m,f[N][N][2],g[N][N][2];
int s[N][N],s2[N][N];
ll ans;
char c[N][N];
int main(){
	cin>>n>>m;
	if(n==1&&m==1){
		printf("1\n");return 0;
	}
	fo(i,1,n){
		scanf("\n");
		fo(j,1,m)c[i][j]=getchar();
	}
	fo(i,1,n)reverse(c[i]+1,c[i]+m+1);
	fo(j,1,m)fo(i,1,n/2)swap(c[i][j],c[n-i+1][j]);
	fo(i,1,n)fo(j,1,m){
		s[i][j]=s2[i][j]=c[i][j]=='R';
		s[i][j]+=s[i][j-1];
		s2[i][j]+=s2[i-1][j];
	}
	f[n][m][0]=f[n][m][1]=1;
	fd(i,1,n)fd(j,1,m){
		add(g[i][j][0],g[i+1][j][0]);
		add(g[i][j][1],g[i][j+1][1]);
		add(f[i][j][0],g[i][j][0]);
		add(f[i][j][1],g[i][j][1]);
		
		add(g[i][j-1][1],f[i][j][0]);
		add(g[i][s[i][j-1]][1],mo-f[i][j][0]);
		
		add(g[i-1][j][0],f[i][j][1]);
		add(g[s2[i-1][j]][j][0],mo-f[i][j][1]);
	}
	add(ans,f[1][1][0]+f[1][1][1]);
	cout<<(ans+mo)%mo;
}