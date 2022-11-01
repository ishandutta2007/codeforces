#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
#define ll long long
#define ld long double
#define pii pair<int,int>
 
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
 
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
 
using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}
#include <unordered_map>
#include <unordered_set>
 
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
 
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
 
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
 
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}
 
template<typename T>
void read(T& a) {
    a = input<T>();
}
 
template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}
 
template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}
 
template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 2e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 1;

ll a[maxn];
ll b[maxn];
int n, k, x;

ll Abs(ll x) {
	return x < 0 ? -x : x;
}

bool canotr() {
	int mnPos = inf;
	int mxOtr = -inf;
	int cntOtr = 0;

	int pos1;
	int pos2;

	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			if (a[i] > mxOtr) {
				mxOtr = a[i];
				pos1 = i;
			}
			cntOtr++;
		} else {
			if (a[i] < mnPos) {
				mnPos = a[i];
				pos2 = i;
			}
		}
	}

	if (cntOtr % 2 == 0) {
		ll val1 = (1LL * (ll)Abs(mxOtr) / x) + 1;
		ll val2 = (1LL * ((ll)mnPos)) / x + 1;
		ll res = min(val1, val2);

		if (res > k)
			return false;
		if (val1 == val2) {
			if (mxOtr + 1LL * val1 * x > Abs(mnPos - 1LL * val2 * x))
				val1 = -1;
			else
				val2 = -1;
		}
		if (val1 < val2) {
			while (a[pos1] <= 0) {
				a[pos1] += x;
				k--;
			}
		} else {
			while (a[pos2] >= 0) {
				a[pos2] -= x;
				k--;
			}
		}
	}

	int kek = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			kek++;
			a[i] += x;
		}
	}
	if (kek > k) {
		return false;
	}

	k -= kek;

	set<pair<ll, int> > q;
	for (int i = 0; i < n; i++)
		q.insert(mp(Abs(a[i]), i));

	while (k && !q.empty()) {
		int pos = (*q.begin()).second;
		q.erase(q.begin());
		if (a[pos] < 0)
			a[pos] -= x;
		else
			a[pos] += x;
		q.insert(mp(Abs(a[pos]), pos));
		k--;
	}

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
		ans *= a[i];
	}
	// cout << ans << endl;
	return true;
}


ll mnres = llinf;
void solve(vector<int> kek, int k, int x) {
    if (!k) {
        ll cur = 1;
        for (int i:kek)
            cur *= i;
        mnres = min(mnres, cur);
        return;
    }
    for (int i = 0; i < kek.size(); i++) {
        vector<int> to = kek;
        to[i] += x;
        solve(to, k - 1, x);
        to[i] -= 2 * x;
        solve(to, k - 1, x);
    }
}

void gentest() {
	srand(time(0));
    ofstream cout("input.txt");
    int n = rand() % 5 + 1;
    int k = rand() % 5 + 1;
    int x = rand() % 100 + 1;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        if (rand() % 2)
            a[i] = -a[i];
    }
    solve(a, k, x);

    cout << n << ' ' << k << ' ' << x << endl;
    for (int i:a)
        cout << i << ' ';
    cout << endl;

    cout << mnres << endl;
}


int main() {
	// gentest();
	// cout << endl;
	//files1;
	read(n, k, x);
	for (int i = 0; i < n; i++) {
		read(a[i]);
		b[i] = a[i];
	}

	int ska = k;

	if (canotr()) {
		exit(0);
	}
	
	k = ska;
	for (int i = 0; i < n; i++) {
		a[i] = b[i];
	}

	// try 0
	for (int i = 0; i < n; i++) {
		if (Abs(a[i]) % x == 0 && Abs(a[i]) / x <= k) {
			a[i] = 0;
			for (int j = 0; j < n; j++)
				cout << a[j] << ' ';
			// cout << 0 << endl;
			exit(0);
		} 
	}

	ll pos, val = llinf;
	for (int i = 0; i < n; i++) {
		if (Abs(a[i]) < val) {
			pos = i;
			val = a[i];
		}
	}

	if (a[pos] < 0)
		a[pos] += 1LL * k * x;
	else
		a[pos] -= 1LL * k * x;


	ll ans = 1;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
		ans *= a[i];
	}
	// cout << ans << endl;
	return 0;
}