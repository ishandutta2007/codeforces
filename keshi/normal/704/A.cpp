//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, ptr, cnt;
vector<ll> vec[maxn], nt;
bool vis[maxn];

int main(){
    fast_io;
    ll t, x;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> t >> x;
        if(t == 1) nt.pb(i), vec[x].pb(i), cnt++;
        else if(t == 2){
            for(ll j : vec[x]){
                if(!vis[j]) cnt--;
                vis[j] = 1;
            }
            vec[x].clear();
        }
        else{
            while(ptr < x){
                if(!vis[nt[ptr]]) cnt--;
                vis[nt[ptr]] = 1;
                ptr++;
            }
        }
        cout << cnt << '\n';
    }


    return 0;
}