#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl

using namespace std;

set < pii > H, V;
multiset < int > mH, mV;
int w, h, n;
string in;

int main(){
    cin >> w >> h >> n;
    H.insert({0, h}), mH.insert(h);
    V.insert({0, w}), mV.insert(w);
    REP(n,i){
        int x;
        cin >> in >> x;
        if (in == "H"){
            auto it = --H.lower_bound({x, x});
            pii p = *it;
            H.erase(it);
            mH.erase(mH.find(p.y - p.x));
            H.insert({p.x, x});
            H.insert({x, p.y});
            mH.insert(x - p.x);
            mH.insert(p.y - x);
        } else {
            auto it = --V.lower_bound({x, x});
            pii p = *it;
            V.erase(it);
            mV.erase(mV.find(p.y - p.x));
            V.insert({p.x, x});
            V.insert({x, p.y});
            mV.insert(x - p.x);
            mV.insert(p.y - x);
        } cout << (ll)(*--mH.end()) * (*--mV.end()) << endl;
    }
    return 0;
}