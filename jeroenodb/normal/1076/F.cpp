#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
void cmax(int& a, int b) {a = max(a,b);}
void no() {
    cout << "NO\n";
    exit(0);
}
int k;
void startWith(int have, int left, int ohave, int& nwleft, int& nwoleft) {
    if(have==0) return;
    if(ohave==0) {
        if(have>left) return;
        nwoleft = k;
        cmax(nwleft, left-have);
        return;
    }
    int dif = have-left;
    int need = (dif+k-1)/k;
    if(dif<0) need=0;
    int needo = (ohave+k-1)/k - 1;
    if(need > ohave or have-1 < needo) {
        // test two extremes
        return;
    }
    if(need==ohave) cmax(nwleft, k - (dif - (need-1)*k));
    else nwleft=k;
    if(have-1==needo) cmax(nwoleft, k- (ohave - (needo-1)*k));
    else nwoleft=k;
};
int main() {
    int n; cin >> n >> k;
    int la=k,lb=k;
    vi x(n),y(n);
    for(auto& i : x) cin >> i;
    for(auto& i : y) cin >> i;
    for(int i=0;i<n;++i) {
        int a = x[i],b=y[i];


        int nla=-1,nlb=-1;
        startWith(a, la, b, nla, nlb);
        startWith(b, lb, a, nlb, nla);
        if(nla==-1 and nlb==-1) no();
        cmax(nla,0); cmax(nlb,0);
        la=nla,lb=nlb;
    }
    cout << "YES\n";
}