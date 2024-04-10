#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 4000010;
const double eps = 1e-9;
// Quick Functions------------------------------------------
// Problem starts here -------------------------------------

int s[maxn], f[maxn], m[maxn];
int p[maxn];
vector<int> d;

const int K = 100;

void backtrack(vector<pair<int,int>> fact,int id,int curr){
    if( id == fact.size() ){
        d.push_back(curr);
        return;
    }
    int to_mul = 1;
    for(int i=0; i<=fact[id].s; i++){
        backtrack(fact,id+1,curr*to_mul);
        to_mul *= fact[id].f;
    }
}

void dv(int x){
    vector<pair<int,int>> fact;
    while( x > 1 ){
        if( fact.empty() || p[x] != fact.back().f )
            fact.push_back({p[x],1});
        else
            fact[fact.size()-1].s ++;
        x /= p[x];
    }
    d.clear();
    backtrack(fact,0,1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, mod;
    cin >> n >> mod;

    f[1] = 1;
    s[1] = 1;
    m[1] = 0;

//    for(int i=1; i<maxn; i++)
//        p[i] = i;
//    for(int i=2; i*i<maxn; i++)
//        if( p[i] == i )
//            for(int j=i*i; j<maxn; j+=i)
//                p[j] = min( p[j] , i );

    for(int i=2; i<=n; i++){
        s[i] = s[i-1];
        m[i] = ( (ll)m[i] + m[i-1] + f[1] ) % mod;
//        dv(i);
//        for( auto j : d ){
//            if( j == i || j == 1 ) continue;
//            m[i] = ( m[i] - f[j-1] + mod ) % mod;
//            m[i] = ( m[i] + f[j] ) % mod;
//        }
        f[i] = ( s[i] + m[i] ) % mod;
        s[i] = ( s[i] + f[i] ) % mod;
        for(int j=i+i; j<=n; j+=i){
            m[j] = ( (ll)m[j] + f[i] - f[i-1] + mod ) % mod;
        }
    }

    cout << f[n] << '\n';

    return 0;
}