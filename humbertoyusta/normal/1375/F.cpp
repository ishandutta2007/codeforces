    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 400010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Pow------------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

ii a[4];
int id[4];

void compute_id(){
    for(int i=0; i<3; i++){
        id[a[i].s] = i;
    }
}

bool can_add_to_a0(int num){
    int aa = a[0].f, bb = a[1].f, cc = a[2].f;
    aa += num;
    int m[3] = { aa , bb , cc };
    sort(m,m+3);
    aa = m[0];
    bb = m[1];
    cc = m[2];
    if( aa == bb || aa == cc || bb == cc ) return false;
    if( cc == a[0].f + num && cc - bb == bb - aa ) return false;
    return true;
}

bool can_add_to_a1(int num){
    int aa = a[0].f, bb = a[1].f, cc = a[2].f;
    bb += num;
    int m[3] = { aa , bb , cc };
    sort(m,m+3);
    aa = m[0];
    bb = m[1];
    cc = m[2];
    if( aa == bb || aa == cc || bb == cc ) return false;
    if( cc == a[1].f + num && cc - bb == bb - aa ) return false;
    return true;
}

bool can_add_to_a2(int num){
    int aa = a[0].f, bb = a[1].f, cc = a[2].f;
    cc += num;
    int m[3] = { aa , bb , cc };
    sort(m,m+3);
    aa = m[0];
    bb = m[1];
    cc = m[2];
    if( aa == bb || aa == cc || bb == cc ) return false;
    if( cc == a[2].f + num && cc - bb == bb - aa ) return false;
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> a[0].f >> a[1].f >> a[2].f;
    a[0].s = 1;
    a[1].s = 2;
    a[2].s = 3;

    sort(a,a+3);
    if( a[0].f == a[1].f && a[1].f == a[2].f ){
        cout << "First\n";
        cout.flush();
        cout << 1 << '\n';
        cout.flush();
        int x;
        cin >> x;
        cout << 1 << '\n';
        cout.flush();
        cin >> x;
        if( x == 0 ) return 0;
            else{ cout << "BAD Case 1=2=3\n"; return 0; };
    }
    if( a[0].f == a[1].f ){
        cout << "First\n";
        cout.flush();
        sort(a,a+3);
        compute_id();
        cout << a[2].f - a[1].f << '\n';
        cout.flush();
        int x;
        cin >> x;
        a[id[x]].f += a[2].f - a[1].f;
        cout << a[2].f - a[1].f << '\n';
        cout.flush();
        cin >> x;
        if( x == 0 ) return 0;
            else{ cout << "BAD Case 1=2\n"; return 0; };
    }
    if( a[1].f == a[2].f ){
        cout << "First\n";
        cout.flush();
        sort(a,a+3);
        compute_id();
        cout << a[1].f - a[0].f << '\n';
        cout.flush();
        int x;
        cin >> x;
        a[id[x]].f += a[1].f - a[0].f;
        cout << max( a[2].f , a[1].f ) - min( a[2].f , a[1].f ) << '\n';
        cout.flush();
        cin >> x;
        if( x == 0 ) return 0;
            else{ cout << "BAD Case 1=3\n"; return 0; };
    }
    int p = a[2].f + ( a[2].f - a[1].f ) - a[0].f;
    int q = a[1].f + ( a[1].f - a[0].f ) - a[2].f;
    int r = a[2].f + ( a[2].f - a[0].f ) - a[1].f;
    if( p == r ){
        cout << "First\n";
        cout.flush();
        sort(a,a+3);
        compute_id();
        cout << p << '\n';
        cout.flush();
        int x;
        cin >> x;
        a[id[x]].f += p;
        sort(a,a+3);
        compute_id();
        p = a[2].f + ( a[2].f - a[1].f ) - a[0].f;
        q = a[1].f + ( a[1].f - a[0].f ) - a[2].f;
        r = a[2].f + ( a[2].f - a[0].f ) - a[1].f;
        cout << p << '\n';
        cout.flush();
        cin >> x;
        a[id[x]].f += p;
        sort(a,a+3);
        compute_id();
        cout << a[2].f - a[1].f << '\n';
        cout.flush();
        cin >> x;
        if( x == 0 ) return 0;
            else{ cout << "BAD Case p=r\n"; return 0; };
    }

    cout << "Second\n";
    cout.flush();
    int x = -1;
    cin >> x;

    vector<int> pra;
    int cnt = 0;
    int last = 0;
    while( x ){
        if( x == 0 ) return 0;
        sort(a,a+3);
        cnt++;
        compute_id();
        pra.pb(x);
        if( can_add_to_a2(x) && last != a[2].s ){ //db("1")
            cout << a[2].s << '\n';
            a[2].f += x;
            last = a[2].s;
            cout.flush();
            cin >> x;
            if( x == -1 ) return 0;
            continue;
        }
        if( can_add_to_a1(x) && last != a[1].s ){ //db("2")
            cout << a[1].s << '\n';
            a[1].f += x;
            last = a[1].s;
            cout.flush();
            cin >> x;
            if( x == -1 ) return 0;
            continue;
        }
        if( can_add_to_a0(x) && last != a[0].s ){ //db("3")
            cout << a[0].s << '\n';
            a[0].f += x;
            last = a[0].s;
            cout.flush();
            cin >> x;
            if( x == -1 ) return 0;
            continue;
        }
        //db(a[0].f)db(a[1].f)db(a[2].f)
        cout << ":" << pra[0] << pra[1] << pra[2] << '\n';
        //cout << cnt << '\n';
        return cnt;
    }

    return 0;
}