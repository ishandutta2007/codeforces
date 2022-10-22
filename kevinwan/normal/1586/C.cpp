#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);

const int mn = 1e6+10;
const ll mod = 1e9+7;

int ded[mn];
string g[mn];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>g[i];
	for(int i=0;i<=max(n,m);i++)ded[i]=0;
	for(int i=0;i+1<n;i++)for(int j=0;j+1<m;j++){
		if(g[i+1][j]=='X'&&g[i][j+1]=='X')ded[j]=1;
	}
	for(int i=1;i<=m;i++)ded[i]+=ded[i-1];
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		--r,--l;
		int num=(r>0?ded[r-1]:0)-(l>0?ded[l-1]:0);
		if(num==0)printf("YES\n");
		else printf("NO\n");
	}
}

void init(){
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	init();
    int tc;
	tc=1;
	while(tc--){
		solve();
	}
}