#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 rng(time(0));
const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=1e5+10;
const ll mod=1e9+7;

int r[mn][5];

bool btr(int a,int b){
	int num=0;
	for(int i=0;i<5;i++)num+=(r[a][i]<r[b][i]);
	return num>=3;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)for(int j=0;j<5;j++)cin>>r[i][j];
		int bes=0;
		for(int i=1;i<n;i++)if(btr(i,bes))bes=i;
		bool suc=1;
		for(int i=0;i<n;i++)if(i!=bes&&!btr(bes,i))suc=0;
		printf("%d\n",suc?bes+1:-1);
	}
}