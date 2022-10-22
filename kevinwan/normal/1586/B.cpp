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

bool u[mn];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++)u[i]=0;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		u[b]=1;
	}
	for(int i=1;i<=n;i++)if(!u[i]){
		for(int j=1;j<=n;j++)if(j!=i){
			printf("%d %d\n",i,j);
		}
		break;
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
	cin>>tc;
	while(tc--){
		solve();
	}
}