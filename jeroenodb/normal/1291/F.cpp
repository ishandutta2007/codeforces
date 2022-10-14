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
void reset(){cout << "R" << endl;}
bool query(int i) {
    cout << "? " << i+1 << endl;
    char c; cin >> c;
    return c=='Y';
}
int main() {
    int n,k; cin >> n >> k;
    vvi dist;
    if(k==1) {
        vi res = {0};
        for(int i=1;i<n;++i) {
            bool good=true;
            for(auto j : res) {
                query(j);
                if(query(i)) {
                    good=false;
                    break;
                }
            }
            if(good) res.push_back(i);
        }
        cout << "! " << res.size() << endl;
        exit(0);
    }
    for(int i=0;i<n;i+=k+1) {
        int r = min(n,i+k+1);
        reset();
        vi cur;
        for(int j=i;j<r;++j) {
            if(!query(j)) cur.push_back(j);
        }
        dist.push_back(cur);
    }
    struct el {
        vi v;
        bool operator<(const el& o) const {return v.size()>o.v.size();}
    };
    priority_queue<el> pq;
    auto merge = [&](vi have, vi v) {
        // split in groups of k/2
        vi res;
        auto it = v.begin();
        while(it!=v.end()) {
            vi cur;
            for(int rep=0;it!=v.end() and rep<k/2+1;++rep) 
                cur.push_back(*(it++));
            int step = k+1 - cur.size();
            for(int j=0;j<(int)have.size();j+=step) {
                reset();
                for(int o=j;o<min((int)have.size(),j+step);++o) query(have[o]);
                vi nv;
                for(auto o : cur) if(!query(o)) nv.push_back(o);
                cur=nv;
            }
            res.insert(res.end(),all(cur));
        }
        have.insert(have.end(),all(res));
        return have;
    };
    for(auto i : dist) pq.push({i});
    while(pq.size()>=2) {
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        auto c = merge(a.v,b.v);
        pq.push({c});
    }
    cout << "! " <<  pq.top().v.size() << '\n';

}