#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct line{
      ll m, c;
      line(ll _m = 0, ll _c = 0){
            m = _m, c = _c;
      }
};

class cht{
      vector<line> st;

public:

      cht(){
            st.clear();
      }

      double getX(line l1, line l2){
            double num = (l1.c - l2.c);
            double den = (l2.m - l1.m);
            return (num / den);
      }

      bool unworthy(line l1, line l2, line l3){
            double x12 = getX(l1, l2);
            double x13 = getX(l1, l3);
            return (x12 >= x13); // => x13 will cover x12.
      }

      void addLine(ll m, ll c){
            line l(m, c);
            while(st.size() >= 2 && unworthy(st[st.size() - 2], st[st.size() - 1], l)){
                  st.pop_back();
            }
            st.push_back(l);
      }

      ll evalY(ll x, line l){
            return (x * l.m + l.c);
      }

      ll getBest(ll x){
            int lo = 0, hi = st.size();
            while(hi - lo > 1){
                  int mid = (lo + hi) >> 1;
                  ll v1 = evalY(x, st[mid-1]);
                  ll v2 = evalY(x, st[mid]);
                  if(v1 < v2){
                        hi = mid;
                  } else {
                        lo = mid;
                  }
            }
            return evalY(x, st[lo]);
      }
};




ll n, m, p, dp[100100][110], dist[100100], sum[100100], idx;
vi mintime;
int main() {
	doin();
	cin >> n >> m >> p;
	for (int i = 2; i <= n; i++) {
		cin >> dist[i];
		dist[i] += dist[i - 1];
	}
	mintime.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> idx >> mintime[i];
		mintime[i] -= dist[idx];
	}
	sort(mintime.begin() + 1, mintime.end());
	for (int i = 1; i <= m; i++)
		sum[i] = sum[i - 1] + mintime[i];
	for (int i = 1; i <= m; i++)
		dp[i][1] = mintime[i] * i - sum[i];
	for (int i = 2; i <= m; i++) {
		dp[i][0] = 1000000000000000000ll;
		dp[i][1] = mintime[i]*i - sum[i];
	}
	for (int pt = 2; pt <= p; pt++) {
		dp[0][pt] = 0;
		cht c;
		c.addLine(0, 0);
		for (int i = 1; i <= m; i++) {
			c.addLine(-i, sum[i] + dp[i][pt - 1]);
			dp[i][pt] = c.getBest(mintime[i]) + (i * mintime[i]) - sum[i];
		}
	}
	cout << dp[m][p];
	return 0;
}