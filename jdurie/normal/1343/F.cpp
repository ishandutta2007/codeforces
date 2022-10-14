#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}
template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator << (ostream &o, T<A...> V) {
	o << '[';
	for(auto a : V) o << a << ", ";
	return o << ']';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

set<ll> s[N], t[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n)
        F(i, 0, n - 1) {
            s[i].clear();
            G(k) F(j, 0, k) { G(x) s[i].insert(x); }
        }
        F(i, 1, n + 1) {
            string ans = "";
            deque<pl> v;
            F(j, 0, n - 1) if(s[j].count(i)) v.emplace_back(s[j].size(), j);
            sort(v.begin(), v.end());
            if(v[0].K != 2) continue;
            bool ok = true;
            F(j, 0, v.size() - 1) {
                for(ll x : s[v[j].V]) if(!s[v[j + 1].V].count(x)) { ok = false; break; }
                if(!ok) break;
            }
            if(ok) {
                ans += to_string(i) + " ";
                F(j, 0, n - 1) t[j] = s[j];
                ll ii = i;
                F(pos, 1, n) {
                    F(j, 0, v.size()) { t[v[j].V].erase(ii); v[j].K--; }
                    while(!v.empty() && !v[0].K) v.pop_front();
                    if(v.empty() || v[0].K > 1) { ok = false; break; }
                    ii = *(t[v[0].V].begin());
                    F(j, 0, v.size()) if(!t[v[j].V].count(ii)) { ok = false; break; }
                    ans += to_string(ii) + " ";
                    F(j, 0, n - 1) if(t[j].count(ii)) v.emplace_back(t[j].size(), j);
                    sort(v.begin(), v.end());
                }
                if(!ok) continue;
                cout << ans << '\n';
                break;
            }
        }
    }
}