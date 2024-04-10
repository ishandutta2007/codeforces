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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n,m; cin >> k >> n >> m;
    vi a(k); 
    for(auto& i : a) cin >> i;

    vector<array<int,3>> improvs(n);
    auto cost = [&](int i) {
        if(i<0) return -oo;
        return improvs[i][2];
    };
    auto comp = [&](int i, int j) {
        return cost(i)>cost(j);
    };

    struct cand {
        ll old, nw;
        int from;
        bool operator<(const cand& o) const {
            return __int128_t(nw)*o.old < __int128_t(o.nw)*old;
        }
    };
    priority_queue<cand> pq;

    vi mults;
    vi bestass(k,-1);
    vvi adds(k);

    {
        int id=0;
        for(auto& [t,i,b] : improvs) {
            cin >> t >> i >> b,--i;
            if(t==1) {
                if(comp(id,bestass[i])) {
                    bestass[i]=id;
                }
            } else if(t==2) {
                adds[i].push_back(id);
            } else if(t==3) {
                if(b!=1) 
                    mults.push_back(id), pq.push({1,b,-1});
            } else assert(false);
            id++;
        }
    }
    for(int i=0;i<k;++i) {
        sort(all(adds[i]),comp); // sort from biggest to smallest
        vector<ll> scores(adds[i].size()+2,-oo);
        scores[0]=a[i];
        int num=0, b = cost(bestass[i]);
        ll sm = 0;
        scores[1] = b;
        for(auto j : adds[i]) {
            ++num;
            sm+=cost(j);
            scores[num] = max(scores[num], sm+a[i]);
            scores[num+1] = max(scores[num+1], sm+b);
        }
        for(int j=1;j<(int)scores.size();++j) {
            if(scores[j-1]>=scores[j]) break;
            pq.push({scores[j-1],scores[j],i});
        }
    }
    vi num(k);
    int mulcnt=0;
    while(!pq.empty() and m) {
        m--;
        auto at = pq.top(); pq.pop();
        if(at.from==-1) mulcnt++;
        else num[at.from]++;
    }
    // nu reconstructen
    sort(all(mults),comp);
    mults.resize(mulcnt);
    vi res;
    for(int i=0;i<k;++i) {
        int b = cost(bestass[i]);
        auto good = [&]() {
            if(num[i]>(int)adds[i].size()) return true;
            if(num[i]==0) return false;
            return b-a[i] > cost(adds[i][num[i]-1]);
        };
        if(good()) {
            res.push_back(bestass[i]);
            num[i]--;
        }
        // assert(num[i]<=(int)adds[i].size());
        num[i] = min(num[i],(int)adds[i].size());
        for(int j=0;j<num[i];++j) res.push_back(adds[i][j]);
    }
    res.insert(res.end(),all(mults));
    cout << res.size() << '\n';
    for(auto i : res) {
        cout << i+1 << ' ';
    }
    
}