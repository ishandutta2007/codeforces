// C++ Template

#include "bits/stdc++.h"
using namespace std;

// Type
typedef long long ll;
typedef long double ld;

// Pair/Vector
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

// Priority Queue
template <class T> using maxpq = priority_queue<T>;
template <class T> using minpq = priority_queue<T, vector<T>, greater<T>>;

// Macro
#define stat(x) (x) && cout << "YES\n" || cout << "NO\n";
#ifdef LOCAL
    #define debug(x) cout << #x << " = " << x << "\n";
#else
    #define debug(x) ;
#endif

// Custom output
template <class A, class B>
ostream& operator << (ostream& out, pair<A, B> x){
    out << "(" << x.first << ", " << x.second << ")";
    return out;
}

template <class T>
ostream& operator << (ostream& out, vector<T> x){
    out << "[";
    for (int i=0; i<(ll)x.size(); i++){
        if (i) out << ", ";
        out << x[i];
    }
    out << "]";
    return out;
}

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
}

// Const
const int interactive = 0;
const ld PI = acos(-1.0);
const ll allmod[2] = {int(1e9)+7, 998244353};
const ll mod = allmod[0];
const ll maxn = 2e5;
const ll inf = 1e18;
const int multitest = 0;

#define int long long

void main_program(){
    int n, k; cin >> n >> k;

    assert(n % 2 == 0);
    assert(k % 2 == 0);

    string s; cin >> s;
    int cnt = 0, crr = 0;
    string res = "";
    for (int i=0; i<n; i++){
    	if (s[i] == '('){
    		if (cnt < k/2){
    			res += '('; cnt++; crr++;
    		}
    	}
    	else{
    		if (crr > 0){
    			res += ')'; crr--;
    		}
    	}
    }

    cout << res;

    // guarantee ton tai
}

void pre_main(){
    
}

signed main(){

    #ifdef LOCAL
        auto start_time = chrono::high_resolution_clock::now();
    #endif

    if (!interactive) {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
    #ifndef ONLINE_JUDGE
        fastio(".inp", ".out");
    #endif

    int t = 1;
    if (multitest) cin >> t;
    pre_main();
    while (t--) main_program();

    #ifdef LOCAL
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
        cout << "\n[" << duration << "ms]\n";
    #endif
}