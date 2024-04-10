#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

template <class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool a) {
    return a ? "T" : "F";
}

string to_string(const char* s) {
    return to_string((string) s);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define X first
#define Y second

using ll = long long;
using ld = long double;

const int N = 1e5 + 10;

int n, k;
int s[N];

void run() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", s + i);
	}
	int sum = 0;
	bool ok = 1;
	vector <int> v;
	for (int i = 0; i < n; ++i) sum += s[i];
	if (sum % k == 0) {
		int d = sum / k;
		int tmp = 0;
		for (int i = 0; i < n; ++i) {
			if (tmp + s[i] <= d) {
				tmp += s[i];
				if (tmp == d) {
					v.push_back(i);
					tmp = 0;
				}
			} else {
				ok = 0;
				break;
			}
		}
		if (v.size() < k) ok = 0;
	} else {
		ok = 0;
	}
	if (ok) {
		puts("Yes");
		for (int i = 0; i < (int)v.size(); ++i) {
			printf("%d%c", v[i] - (i ? v[i - 1] : -1), " \n"[i == (int)v.size() - 1]);
		}
	} else {
		puts("No");
	}
}

int main() {
    run();
    return 0;
}