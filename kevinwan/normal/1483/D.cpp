#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=600+10;

ll d[mn][mn],av[mn][mn],o[mn][mn];
int bes[mn][mn];
void hailveshy(){
	int n,m;
	cin>>n>>m;
	memset(d,0x3f,sizeof(d));
	memset(o,0x3f,sizeof(o));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=0;i<m;i++){
		int a,b,l;
		cin>>a>>b>>l;
		d[a][b]=d[b][a]=o[a][b]=o[b][a]=l;
	}
	int q;
	cin>>q;
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		av[a][b]=av[b][a]=c;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		ll cb=LLONG_MAX;
		for(int k=1;k<=n;k++){
			ll cand=d[j][k]-av[i][k];
			if(cand<cb)cb=cand,bes[i][j]=k;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<i;j++){
		if(o[i][j]==0x3f3f3f3f3f3f3f3f)continue;
		bool gud=0;
		for(int k=1;k<=n;k++){
			int l=bes[k][j];
			if(d[k][i]+o[i][j]+d[j][l]<=av[k][l]){
				gud=1;
				break;
			}
		}
		ans+=gud;
	}
	printf("%d\n",ans);
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc=1;
	//cin>>tc;
	for(int tcc=1;tcc<=tc;tcc++){
		hailveshy();
	}
}