#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree() {
        int sz = 100050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = (node[2*i+1] + node[2*i+2]);
    }
 
    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};

priority_queue<l_l, vector<l_l>, greater<l_l>> query;
queue<ll> que;
set<ll> st;
SegmentTree seg;
ll ans[100050];
bool occupied = false;
void f() {
    if(st.empty()) return;
    auto itr = st.begin();
    int person = *itr;
    //cerr << "f: " << person << " " << seg.getsum(0, person) << endl;
    if(seg.getsum(0, person) == person - 1) {
        que.push(person);
        seg.update(person, 0);
        st.erase(itr);
    }
}
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, p;
    cin >> N >> p;
    for(int i = 1; i <= N; i++) {
        seg.update(i, 1);
        ll t;
        cin >> t;
        query.push({t, i});
    }
    while(!query.empty()) {
        l_l now = query.top();
        //cerr << now.first << " " << now.second << endl;
        query.pop();
        if(now.second < 0) {
            ans[-now.second] = now.first;
            seg.update(-now.second, 1);
            occupied = false;
            /*
            if(!que.empty()) {
                query.push({now.first + p, -que.front()});
                que.pop();
            } else {
                occupied = false;
            }
            */
        } else {
            st.insert(now.second);
        }
        if(query.empty() || query.top().first != now.first) {
            f();
            if(!occupied && !que.empty()) {
                //cerr << que.front() << endl;
                    query.push({now.first + p, -que.front()});
                    que.pop();
                    occupied = true;
            }
        }
    }
    for(int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}