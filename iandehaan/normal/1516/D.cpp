#include <bits/stdc++.h>
using namespace std;

using ll = long long;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair


const int LIM = 350;
bitset<LIM> isPrime;
vi eratosthenes() {
	const int S = (int)round(sqrt(LIM)), R = LIM / 2;
	vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
		cp.push_back({i, i * i / 2});
		for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
	}
	for (int L = 1; L <= R; L += S) {
		array<bool, S> block{};
		for (auto &[p, idx] : cp)
			for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
		rep(i,0,min(S, R - L))
			if (!block[i]) pr.push_back((L + i) * 2 + 1);
	}
	for (int i : pr) isPrime[i] = 1;
	return pr;
}

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> pr = eratosthenes();

    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> primes[n];
    unordered_map<int, vector<int>> usedprimes;
    for (int i = 0; i < n; i++) {
        for (int p : pr) {
            if (a[i] % p == 0) {
                a[i] /= p;
                primes[i].pb(p);
                usedprimes[p].pb(i);
            }
            while (a[i] % p == 0) a[i] /= p;
        }
        if (a[i] != 1) {
            primes[i].pb(a[i]);
            usedprimes[a[i]].pb(i);
        }
    }


    vector<int> nxt(n);
    for (int i = 0; i < n; i++) {
        nxt[i] = n;
    }

    for (pair<int, vector<int>> pp : usedprimes) {
        for (int j = 1; j < pp.second.size(); j++) {
            nxt[pp.second[j-1]] = min(nxt[pp.second[j-1]], pp.second[j]);
        }
    }

    RMQ<int> rangemin(nxt);

    int sqrtn = 1;
    while (sqrtn*sqrtn < n) sqrtn++;

    int sqrtr[n];

    for (int i = 0; i < n; i++) {
        int l = i;
        for (int j = 0; j < sqrtn; j++) {
            if (l == n) break;
            l = rangemin.query(l, n);
        }
        sqrtr[i] = l;
    }

    while (q--) {
        int out = 0;
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        while (sqrtr[l] <= r) {
            l = sqrtr[l];
            out += sqrtn;
            if (l == n) break;
            //cout << "yooo" << endl;
        }
        while (l <= r) {
            l = rangemin.query(l, r+1);
            out++;
            //cout << "L: " << l << endl;
        }
        cout << out << endl;
    }




}