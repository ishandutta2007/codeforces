#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define K first
#define V second
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

template<class T, class S>
ostream& operator<<(ostream& o, pair<T, S> p) {
	return o<<'('<<p.K<<", "<<p.V<<')';
}

template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator<< (ostream& o, T<A...> v) {
	o<<'[';
	for (auto a:v) o<<a <<", ";
	return o<<']';
}

void _print() {cerr << "]\n";} template <class T, class... V>
void _print(T t, V... v) {cerr<<t; if (sizeof...(v)) cerr << ", "; _print(v...);}
#define D(x...) do {cerr << "[" << #x << "] = ["; _print(x); } while(0);
#define DF(i, s, e, x...) do { for (ll i=(s); i<(e); ++i) {cerr<<i<<": "; D(x)} } while(0);

#define G(x) ll x; cin>>x;
#define F(i, l, r) for (ll i=l; i<(r); ++i)
#define all(x) (x).begin(), (x).end()
#define TC ll ntests;cin>>ntests;ll tc=0;goto _restart;_restart:;while(++tc<=ntests)
#define EXT(x) {cout<<x<<'\n'; goto _restart;}
#define EX(x) {cout<<x<<'\n'; exit(0);}
#define NN 100010
constexpr ll M = 1e9+7; // 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    string s;
    cin>>s;
    ll n = s.size();
    if (s.size()==1) {
        if (s[0]=='0' || s[0]=='_' || s[0]=='X') EX(1)
        else EX(0)
    }
    
    if (s[0]=='0') EX(0)

    ll ans=0;
    string c[]={"00", "25", "50", "75"};
    for (auto pos:c) {
        string t = s;
        ll x=0;
        char xv=-1;
        if (t[n-2]=='X' && t[n-1]!='X') {
            t[n-2] = pos[0];
            x=1;
            xv = pos[0];
        } else if( t[n-1]=='X' && t[n-2]!='X') {
            t[n-1]=pos[1];
            x=1;
            xv=pos[1];
        }
        if (t[n-1]=='X') {
            t[n-2] = pos[0];
            t[n-1] = pos[0];
            x=1;
            xv=pos[0];
        }

        if (t[n-2]=='_') t[n-2]=pos[0];
        if (t[n-1]=='_') t[n-1]=pos[1];
        if (t.substr(n-2)!=pos) continue;
        if (t.size()==2 && t[0]=='0') continue;

        if (t.size()==2) {
            ans++;
            continue;
        }

        ll way=1;
        for (ll i=0; i<n-2; ++i) {
            if (t[i]=='_') {
                if (i) way *= 10;
                else way *= 9;
            }
            else if (t[i]=='X') {
                if (!x) {
                    if (i) way *= 10;
                    else way *= 9;
                } else {
                    if (xv=='0' && i==0) goto done;
                }
                x=1;
            }
        }
        ans += way;
        done:;
    }

    cout<<ans<<endl;
}