#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef double ld;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef priority_queue<pl, vector<pl>, greater<pl> > pq;
 
template<class T, class S>
ostream& operator<<(ostream &o, pair<T, S> p) {
    return o<<'('<<p.first<<", "<<p.second<<')';
}
 
template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator<<(ostream &o, T<A...> V) {
	o<<'[';
	for(auto a:V) o<<a<<", ";
	return o<<']';
}
 
// This is tuples, _p is helper
template<ll i, class... T>
typename enable_if<i==sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {}
 
template<ll i, class... T>
typename enable_if<i<sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {
    _p<i+1>(o << get<i>(t)<< ", ", t);
}
 
template<class... T>
ostream& operator<<(ostream& o, tuple<T...> t) {
    _p<0>(o<<'(', t);
    return o<<')';
}
 
 
#define G(x) ll x; cin >> x;
#define Gs(s) string s; cin >> s;
#define Gd(x) ld x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define F1(i, l, r) for(ll i = l; i >= (r); i--)
#define Fi(i, s) for(auto i = (s).begin(); i != (s).end(); i++)
#define L G(_t) F(_t1, 0, _t)
#define H(ar, n) vector<ll> ar(n); F(_i, 0, n) cin >> ar[_i];
#define A first
#define B second
#define PA(ar, n) F(_i, 0, n) cout << (ar)[_i] << " "; cout << endl; 
#define PB push_back
#define V vector
#define CASE cout << "Case #" << _t1 + 1 << ": " 
#define CC << " " <<
#define BE(ar) ar.begin(), ar.end()
#define CO(x) cout << (x) << endl;
#define D(x) ((x) - '0')
#define EX(x) {cout << (x) << endl; return 0;}
#define S(ar, val) memset(ar, val, sizeof(ar));
ll M = 1000000007; //998244353;
ll inv(ll a, ll b){return 1<a ? b - inv(b%a,a)*b/a : 1;}
ll gcd(ll x, ll y){if(y == 0) return x; return gcd(y, x % y); }
pl neigh[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
 
#define N 0
 
ll n, k;
V<pl> v;
const ld ep=1e-8;
const ld PI = acos(-1);

ld getNum(ld a, ld b, ld c){
    return (a*a+b*b-c*c)/(2*a*b);
}

ld lc(ld a, ld b, ld c){
    return acos(getNum(a, b, c));
}

bool can(ld r){
    V<pair<ld, bool>> sweep;
    F(i, 0, n){
        ld dist = sqrtl(v[i].A*v[i].A+v[i].B*v[i].B);
        ld num = getNum(r, dist, r);
        ld ang = fmod(atan2(v[i].B, v[i].A) + 2 * PI, 2 * PI);
        if (abs(num) < 1.0 + ep) {
          ld ang2 = fmod(acos(num) + 2 * PI, 2 * PI);
          ld ent = fmod(ang - ang2 + 2 * PI, 2 * PI);
          ld ex = ent+2*ang2;
          F(j, 0, 4){
            sweep.PB({ent + 2 * PI * j, true});
            sweep.PB({ex + 2 * PI * j, false});
          }
        }
    }
    sort(BE(sweep));
    ll ma = 0;
    ll c = 0;
    F(i, 0, sweep.size()){
        c += sweep[i].B ? 1 : -1;
        ma = max(c, ma);
    }
    return ma >= k;
}

ld solve(ld l, ld r){
    if(abs(l-r)<ep) return l;
    ld mid = (l+r)/2;
    if(can(mid)) return solve(l, mid);
    return solve(mid, r);
}

int main() {
    cin >> n >> k;
    F(i, 0, n){
        G(x) G(y)
        v.PB({x, y});
        if(x == 0 && y == 0) k--;
    }
    //cout << can(3.17) << endl;
    cout << setprecision(18) << solve(0, 200000) << endl;
}