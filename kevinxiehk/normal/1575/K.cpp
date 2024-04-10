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
#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define dbg(W) cerr<<(#W)<<"::"<<(W)<<'\n'
#define RTE cout<<__LINE__<<'\n',exit(0)
using namespace std;
using namespace __gnu_pbds;
using pii=pair <int,int>;
using tii=tuple<int,int,int>;
template <typename T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1000000007ll;
int bigmod(int b,int p){
    b%=mod;
    if (!b) return 0;
    int ans=1;
    while (p){
        if (p&1ll){
            ans*=b;
            ans%=mod;
        }
        p>>=1ll;
        b*=b;
        b%=mod;
    }
    return ans;
}
inline void solve(){
	int n,m,k,r,c;
    cin>>n>>m>>k>>r>>c;
    int ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    if (ax>bx||ax==bx&&ay>by){
        swap(ax,bx);
        swap(ay,by);
    }
    if (bx-ax>=r||by-ay>=c){
        cout<<bigmod(k,n*m-r*c);
    } else if (ax==bx&&ay==by){
        cout<<bigmod(k,n*m);
    } else {
        cout<<bigmod(k,n*m-r*c);
    }
    cout<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t=1;
//	cin>>t;
	for (int i=1; i<=t; i++) solve();
}