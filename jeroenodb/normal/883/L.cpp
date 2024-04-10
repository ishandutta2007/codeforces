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
vi x;
vector<ll> av;
struct comp {
    bool operator()(int i, int j) const {
        if(x[i]!=x[j]) return x[i]<x[j];
        if(av[i]!=av[j]) return av[i]<av[j];
        return i <j;
    }
};
struct comp2 {
    bool operator()(int i, int j) const {
        return av[i]>av[j];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m; cin >> n >> k >> m;
    x.resize(k),av.resize(k,-1);

    set<int,comp> s;
    ll t=0;
    for(auto& i : x) cin >> i;
    for(int i=0;i<k;++i) s.insert(i);
    x.push_back(-1);
    av.push_back(-2);
    priority_queue<int,vi,comp2> pq;
    while(m--) {
        ll wt; int a,b;
        cin >> wt >> a >> b;
        t = max(wt,t);
        while(!pq.empty()) {
            auto i = pq.top();
            if(av[i]<=t or s.empty()) {
                // taxi becomes available
                t=max(t,av[i]);
                s.insert(i);
                pq.pop();
            } else break;
        }
        
        x.back()=a;
        auto it = s.lower_bound(k);
        int cand=-1;
        if(it!=s.end()) {
            cand = *it;
        }
        if(it!=s.begin()) {
            --it;
            x.back()=x[*it];
            it = s.lower_bound(k);
            if(cand==-1) cand=*it;
            else {
                if(make_tuple(abs(a-x[cand]),av[cand],cand)>make_tuple(abs(a-x[*it]),av[*it],*it)) 
                    cand=*it;
            }
        }
        ll waittime = abs(x[cand]-a)+t-wt;
        cout << cand+1 << ' ' << waittime << '\n';
        s.erase(cand);
        av[cand] = abs(x[cand]-a)+t+abs(b-a);
        x[cand]=b;
        pq.push(cand);

    }
}