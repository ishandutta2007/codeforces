#include <bits/stdc++.h>
using namespace std;

#define int long long

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& s) {
    string res = "'";
    res += s;
    res += "'";
    return res;
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (i) res += ", ";
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(15);
	int n, d, m;
	cin >> n >> d >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> pref(n + 1);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}
	int lastm = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] <= m) lastm = i + 1;
	}
	int ans = pref[lastm] + (a[n - 1] > m) * a[n - 1];
	int x = lastm, y = n - x;
	for (int banned = 0; banned < n; ++banned) {
		int cnt = (banned + d - 1) / d;
		if (banned % d == 0 && (!(cnt + 1 + banned < y || cnt + 1 + banned > n || cnt + 1 > y))) {
			int new_ans = pref[n] - pref[n - cnt - 1];
			int banned2 = banned - (y - (cnt + 1));
			new_ans += pref[lastm] - pref[banned2];
			ans = max(ans, new_ans);
		}
		{
		    if (cnt + banned < y || cnt + banned > n || cnt > y) continue;
			int new_ans = pref[n] - pref[n - cnt];
			int banned2 = banned - (y - (cnt));
			new_ans += pref[lastm] - pref[banned2];
			ans = max(ans, new_ans);
		}
	}
	cout << ans;
}