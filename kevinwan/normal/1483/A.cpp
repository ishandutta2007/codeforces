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
const int mn=2e5+10;

vector<int>f[mn];
int ans[mn],num[mn];

void hailveshy(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)f[i].clear(),ans[i]=0;
	for(int i=1;i<=n;i++)num[i]=(m+1)/2;
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		int x;
		for(int j=0;j<k;j++)cin>>x, f[i].push_back(x);
		
	}
	for(int i=0;i<m;i++)if(f[i].size()==1){
			ans[i]=f[i][0];
			num[ans[i]]--;
			if(num[ans[i]]<0){
				printf("NO\n");
				return;
			}
		}
	for(int i=0;i<m;i++)if(f[i].size()>1){
		if(num[f[i][0]]){
			ans[i]=f[i][0];
		}
		else ans[i]=f[i][1];
		num[ans[i]]--;
	}
	printf("YES\n");
	for(int i=0;i<m;i++)printf("%d ",ans[i]);
	printf("\n");
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	for(int tcc=1;tcc<=tc;tcc++){
		hailveshy();
	}
}