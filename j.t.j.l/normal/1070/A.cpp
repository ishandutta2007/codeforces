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

const int D = 510, S = 5010;

int d, s;

int dis[D][S];
pair < pair <int, int>, int> pre[D][S];

void bfs() {
	memset(dis, -1, sizeof(dis));
	queue < pair <int, int> > q;
	dis[0][0] = 0;
	q.emplace(0, 0);
	while (!q.empty()) {
		auto t = q.front();
		debug(dis[t.X][t.Y], t);
		q.pop();
		for (int i = 0; i < 10; ++i) {
			pair <int, int> nt = {(t.X * 10 + i) % d, t.Y + i};
			if (t.Y + i > s) {
				break;
			}
			if (dis[nt.X][nt.Y] == -1) {
				dis[nt.X][nt.Y] = dis[t.X][t.Y] + 1;
				pre[nt.X][nt.Y] = make_pair(t, i);
				q.push(nt);
			}
		}
	}
	function <void(int, int, vector <int>&)> go = [&](int d, int s, vector <int> &v) {
		if (d == 0 && s == 0) return;
		auto pp = pre[d][s];
		auto p = pp.X;
		v.push_back(pp.Y);
		go(p.X, p.Y, v);
	};
	if (dis[0][s] == -1) {
		puts("-1");
	} else {
		vector <int> v;
		debug(0, s);
		go(0, s, v);
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i) printf("%d", v[i]);
		puts("");
	}
}

void run() {
	scanf("%d%d", &d, &s);
	bfs();
}

int main() {
    run();
    return 0;
}