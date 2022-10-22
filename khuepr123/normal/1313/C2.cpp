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
    int n; cin >> n;
    vi v(n);
    for (auto &i: v) cin >> i;

    stack<int> st;

	vi l(n), r(n);

	for (int i=0; i<n; i++){
		while ((!st.empty()) && v[st.top()] >= v[i]) st.pop();

		if (st.empty()) l[i] = v[i] * (i+1);
		else l[i] = l[st.top()] + (i - st.top()) * v[i];

		st.push(i);
	}

	while (!st.empty()) st.pop();

	for (int i = n-1; i>=0; i--){
		while ((!st.empty()) && v[st.top()] >= v[i]) st.pop();

		if (st.empty()) r[i] = v[i] * (n-i);
		else r[i] = r[st.top()] + (st.top() - i) * v[i];

		st.push(i);
	}

	int peak, val = -inf;

	for (int i=0; i<n; i++){
		if (val < l[i] + r[i] - v[i]){
			val = l[i] + r[i] - v[i];
			peak = i;
		}
	}

	int crr = v[peak];
	vi res(n);

	for (int i = peak; i >= 0; i--){
		if (v[i] < crr) crr = v[i];
		res[i] = crr;
	}

	crr = v[peak];

	for (int i = peak; i < n; i++){
		if (v[i] < crr) crr = v[i];
		res[i] = crr;
	}

	for (int i=0; i<n; i++){
		cout << res[i] << " ";
	}
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