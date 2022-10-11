#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;
vector<int> v1, v2;
vector<pii> v;
int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a, b;
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
        v.push_back({a, b});
    }
    sort(all(v1));
    reverse(all(v1));
    sort(all(v2));
    int ans = 0;
    int j = 0, f = -1;
    for(auto x:v){
        if(x.F == v1[0] && x.S == v2[0]){
            f = j;
            break;
        }
        j++;
    }
    if(f + 1){
        int p1 = -1, p2 = 1e9;
        for(int i = 0 ; i < n; i++){
            if(i != f){
                p1 = max(p1, v[i].F);
                p2 = min(p2, v[i].S);
            }
        }
        ans = max(0, p2 - p1);
        return cout << ans, 0;
    }
    ans = max(ans, v2[1] - v1[0]);
    ans = max(ans, v2[0] - v1[1]);
    cout << ans;
    return 0;
}