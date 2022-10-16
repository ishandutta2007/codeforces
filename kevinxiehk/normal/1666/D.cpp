#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define x first
#define y second
#define pb push_back
#define br break
#define ct continue
#define rt return
#define vt vector
#define gt greater
#define prq priority_queue
#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define dbg(W) cerr<<(#W)<<"::"<<(W)<<'\n'
#define dbga(V) cerr<<(#V)<<"::";for(auto&i:V)cout<<i<<' ';cerr<<'\n'
#define RTE cerr<<__LINE__<<'\n',exit(0)
using namespace std;
using namespace __gnu_pbds;
using pii=pair <int,int>;
using tii=pair <pii,int>;
using rii=pair <int,pii>;
using qii=pair <pii,pii>;
const int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,-1,1};
template <typename T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <typename T> using rset=tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1000000007ll;
//const int mod=998244353ll;
mt19937 mt(time(nullptr));
void solve(){
	string s,t;
	cin>>s>>t;
	bool used[s.size()]={};
	int ptr=t.size()-1;
	for (int i=s.size()-1; i>=0; i--){
		if (s[i]==t[ptr]){
			ptr--;
			used[i]=1;
		}
		if (ptr==-1) break;
	}
	if (ptr!=-1){
		nn;
		rt;
	}
	vector <int> lst[26];
	for (int i=0; i<s.size(); i++) lst[s[i]-'A'].pb(i);
	//RTE;
	for (int i=s.size()-1; i>=0; i--){
		if (!used[i]){
			continue;
		}
		if (lst[s[i]-'A'].back()!=i){
			nn;
			rt;
		} else {
			lst[s[i]-'A'].pop_back();
		}
	}
	yy;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t=1;
	cin>>t;
	while (t--) solve();
}