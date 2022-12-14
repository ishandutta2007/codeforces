#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define pb push_back
#define ll long long
#define mod 998244353
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int T,n,a[N][N],i,j,p[N];
void solve(int x,int y,int pos,int sy){
	if(!sy)return ;
	if(a[x+1][y]||x==n)a[x][y]=pos,solve(x,y-1,pos,sy-1);
	else a[x][y]=pos,solve(x+1,y,pos,sy-1);
} 
int main(){
		cin>>n;
		for(i=1;i<=n;++i)
			cin>>p[i];
	for(i=n;i>n-p[n];--i)a[n][i]=p[n];
	for(i=n-1;i;--i){
		solve(i,i,p[i],p[i]);
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=i;++j)cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}