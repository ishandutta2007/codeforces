#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
//#define N 100010

string s;
ll n, k, tot, ct[256];

void fillms() {
    F(ch, 'a', 'z' + 1) {
        ll z = (k - ct[ch] % k) % k;
        ct[ch] += z, tot += z;
    }
    ct['a'] += n - tot;
}

bool ok(ll i) {
    fill_n(ct + 'a', 26, 0); tot = i;
    F(j, 0, i) ct[s[j]]++;
    ll num = 0;
    F(ch, 'a', 'z' + 1) num += (ct[ch] + k - 1) / k;
    if(num < n / k) {
        ct[s[i] + 1]++;
        tot++;
        fillms();
        return true;
    } else if(num == n / k) {
        F(ch, 'a', 'z' + 1) if(ct[ch] % k && ch > s[i]) { fillms(); return true; }
        return false;
    } else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> k >> s;
        bool b = true;
        F(i, 0, 26) if(count(A(s), 'a' + i) % k) b = false;
        if(b || k == 1) cout << s << '\n';
        else if(n % k) cout << "-1\n";
        else {
            ll num = 0, bst = -1;
            fill_n(ct + 'a', 26, 0);
            F(i, 0, n) {
                if(s[i] - 'z') {
                    if(num < n / k) bst = i;
                    else if(num == n / k) {
                        F(ch, 'a', 'z' + 1) if(ct[ch] % k && ch > s[i]) bst = i;
                    }
                }
                ct[s[i]]++;
                if(ct[s[i]] % k == 1) num++;
            }
            if(bst == -1) cout << "-1\n";
            else {
                ok(bst);
                cout << s.substr(0, bst);
                F(i, 0, bst) ct[s[i]]--;
                char c = '$';
                F(ch, s[bst] + 1, 'z' + 1) if(ct[ch]) { c = ch; break; }
                cout << c;
                ct[c]--;
                F(ch, 'a', 'z' + 1) while(ct[ch]--) cout << (char)ch;
                cout << '\n';
            }
        }
    }
}