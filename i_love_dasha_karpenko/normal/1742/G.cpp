#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
const int LOG = 30;
bool vis[N];
int A[N],org[N];
vector<int> V[LOG];
void solve(){
	for(int i = 0;i<LOG;i+=1){
		V[i].clear();
	}
	int n;
	cin>>n;
	for(int i = 0;i<=n;i+=1){
		vis[i] = 0;
	}
	set<pair<int,int> > S;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
		for(int bit = 0;bit<LOG;bit+=1){
			if ((A[i]>>bit)%2){
				V[bit].push_back(i);
			}
		}
		org[i] = A[i];
		S.insert({A[i],i});
	}
	for(int i = 1;i<=n;i+=1){
		int v = S.rbegin()->second;
		vis[v] = 1;
		S.erase(prev(S.end()));
		cout<<org[v]<<' ';
		for(int bit = 0;bit<LOG;bit+=1){
			if ((A[v]>>bit)%2){
				for(int to:V[bit]){
					if (vis[to]){
						continue;
					}
if ((A[to]&((1<<LOG)-1-A[v]))==A[to]) continue;
					S.erase({A[to],to});
					A[to] &= (1<<LOG)-1-A[v];
					S.insert({A[to],to});
				}
				V[bit].clear();
			}
		}
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	for(int tt = 1;tt<=t;tt+=1){
		solve();
	}
}