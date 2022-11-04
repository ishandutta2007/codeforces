#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=2020,mod=1e9+7;
ll d[N][N],r[N][N];
ll sd[N][N],sr[N][N];
ll pd[N][N],pr[N][N];
string f[N];
int n,m;
main(){
	cin>>n>>m;
	if(n==1&&m==1){cout<<1<<endl;return 0;}
	for(int i=0;i<n;++i)cin>>f[i];
	for(int i=0;i<n;++i)
		for(int j=m-1;j>=0;--j)
			sr[i][j]=sr[i][j+1]+(f[i][j]=='R');
	for(int i=n-1;i>=0;--i)
		for(int j=0;j<m;++j)
			sd[i][j]=sd[i+1][j]+(f[i][j]=='R');
	pr[n-1][m-1]=pd[n-1][m-1]=r[n-1][m-1]=d[n-1][m-1]=1;
	for(int i=n-1;i>=0;--i)
		for(int j=m-1;j>=0;--j)
			if(i!=n-1||j!=m-1){
				r[i][j]=(pd[i][j+1]-pd[i][m-sr[i][j+1]]+mod)%mod;
				pr[i][j]=(r[i][j]+pr[i+1][j])%mod;
				d[i][j]=(pr[i+1][j]-pr[n-sd[i+1][j]][j]+mod)%mod;
				pd[i][j]=(d[i][j]+pd[i][j+1])%mod;
			}
			
	cout<<(r[0][0]+d[0][0])%mod<<endl;
}