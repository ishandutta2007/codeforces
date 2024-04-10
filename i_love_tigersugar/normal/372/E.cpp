//This code is copied from rng_58
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
struct frac {ll x,y;}; // x/y
#define _abs(x) ((x)>0?(x):-(x))
ll gcd(ll x, ll y) {return x ? gcd(y%x,x) : y;}
frac make_frac(ll x, ll y) {if(y < 0) {x = -x; y = -y;} ll d = gcd(_abs(x),_abs(y)); frac f = {x/d,y/d}; return f;}
frac sum(frac &f1, frac &f2) {ll x = f1.x * f2.y + f1.y * f2.x; ll y = f1.y * f2.y; return make_frac(x,y);};
double val(frac &f) {return (double)f.x / f.y;};

struct point {frac x,y;};

int N;
point P[1010];
pair <pair <pair <ll, ll>, pair <ll, ll> >, pair <int, int> > Q[500010];

#define MOD 1000000007ll
#define PI acos(-1.0)
#define eps 1.0E-9
vector <double> v;
vector <int> freq;

ll count(void){
    int n=v.size(),i,j;
    
    sort(v.begin(),v.end());
    
    // cout << n << endl;
    
    freq.clear();
    i = 0;
    while(i < n){
        for(j=i;j<n;j++) if(v[j] - v[i] > eps) break;
        freq.push_back(j-i);
        i = j;
    }
    
    if(freq.size() < 2) return 0;
    
    ll ans = 1;
    REP(i,freq.size()) ans = ans * (freq[i] + 1) % MOD;
    REP(i,freq.size()) ans -= freq[i];
    ans--;
    ans = (ans + MOD) % MOD;
    return ans;
}

ll func(int K){
    if(K < 2) return 0;
    ll ans = 1;
    int i;
    REP(i,K) ans = ans * 2 % MOD;
    ans = (ans - K - 1 + MOD) % MOD;
    return ans;
}

int main(void){
    int i,j,k;
    
    cin >> N;
    REP(i,N){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        P[i].x = make_frac(a*b*d*d, a*a*d*d+b*b*c*c);
        P[i].y = make_frac(b*b*c*d, a*a*d*d+b*b*c*c);
    }
    
    int sz = 0;
    REP(i,N) REP(j,i){
        frac x = sum(P[i].x, P[j].x);
        frac y = sum(P[i].y, P[j].y);
        Q[sz] = make_pair(make_pair(make_pair(x.x, x.y), make_pair(y.x, y.y)), make_pair(i, j));
        sz++;
    }
    
    sort(Q, Q+sz);
    ll ans = 0;
    i = 0;
    while(i < sz){
        for(j=i;j<sz;j++) if(Q[j].first != Q[i].first) break;
        
        v.clear();
        for(k=i;k<j;k++){
            int p = Q[k].second.first;
            int q = Q[k].second.second;
            double dx = val(P[p].x) - val(P[q].x);
            double dy = val(P[p].y) - val(P[q].y);
            double theta = atan2(dy, dx) - 7.0;
            while(theta < 0.0) theta += PI;
            v.push_back(theta);
        }
        
        ll tmp = count();
        ans = (ans + tmp) % MOD;
        i = j;
    }
    
    cout << ans << endl;
    
    return 0;
}