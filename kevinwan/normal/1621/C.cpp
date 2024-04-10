#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=1e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;


bool vis[mn];
int p[mn];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)vis[i]=p[i]=0;
	for(int s=1;s<=n;s++){
		if(vis[s])continue;
		int val=-1,cur=-2;
		while(cur<0||!vis[cur]){
			if(cur>=0)vis[cur]=1;
			cout<<"? "<<s<<endl;
			int nxt;
			cin>>nxt;
			if(val==-1)val=cur=nxt;
			else{
				p[cur]=nxt;
				cur=nxt;
			}
		}
	}
	cout<<"!";
	for(int i=1;i<=n;i++)cout <<" "<< p[i];
	cout << endl;
}

int main() {
	//cin.tie(0);
	//cin.sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}