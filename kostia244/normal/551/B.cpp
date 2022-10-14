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
typedef __V <__V<_I> > vvi;
typedef __V <__V<char> > vvc;
typedef __V <__V<pi> > vvpi;
//using AntonTsypko = void;
//using arsijo = AntonTsypko;
//using bog = arsijo;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int calc(string s, string a, string b) {
    int fs[26] = {0}, fa[26] = {0}, fb[26] = {0};
    for(int i = 0; i < s.size(); i++) {
        fs[s[i] - 'a']++;
    }
    for(int i = 0; i < a.size(); i++) {
        fa[a[i] - 'a']++;
    }
    for(int i = 0; i < b.size(); i++) {
        fb[b[i] - 'a']++;
    }
    int oa = INT_MAX, ob = INT_MAX;
    for(int i = 0; i < 26; i++) if(fa[i]) oa = min(fs[i]/fa[i], oa);
    for(int i = 0; i < 26; i++) fs[i] -= fa[i]*oa;
    for(int i = 0; i < 26; i++) if(fb[i]) ob = min(fs[i]/fb[i], ob);
    for(int i = 0; i < 26; i++) fs[i] -= fb[i]*ob;
    return oa+ob;
}

string s, a, b;
int main() {
    doin();
    cin >> s >> a >> b;
    if(calc(s, b, a) > calc(s, a, b)) swap(a, b);
    int fs[26] = {0}, fa[26] = {0}, fb[26] = {0};
    for(int i = 0; i < s.size(); i++) {
        fs[s[i] - 'a']++;
    }
    for(int i = 0; i < a.size(); i++) {
        fa[a[i] - 'a']++;
    }
    for(int i = 0; i < b.size(); i++) {
        fb[b[i] - 'a']++;
    }
    int ma = 0, ok = 1, mx = 0, l = s.size()/a.size();
    for(int ac = 0; ok; ac++) {
        int nb = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(ac)
                fs[i] -= fa[i];
            if(fs[i] < 0) {
                nb = 0;
                ac = 0;
                ok = 0;
                break;
            }
            if(fb[i])
                nb = min(nb, fs[i]/fb[i]);
        }
        if(ok && mx < (nb+ac))
        mx = nb+ac, ma = ac;
    }
        for(int i = 0; i < 26; i++) fs[i] = 0;
    for(int i = 0; i < s.size(); i++) {
        fs[s[i] - 'a']++;
    }
    int mb = mx - ma;
    for(int i = 0; i < 26; i++) fs[i] -= fa[i]*ma;
    for(int i = 0; i < 26; i++) fs[i] -= fb[i]*mb;
    while(ma--)
        cout << a;
    while(mb--)
        cout << b;
    for(int i = 0; i < 26; i++) while(fs[i]--) cout << char('a'+i);


}