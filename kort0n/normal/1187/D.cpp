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
int a[350000];
int b[305000];
int indexes[305000]; // a[indexes[i]] = b[i];
int invindexes[305000];
queue<int> que[305000];
bool NG = false;
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree(int _n) {
        int sz = _n;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = INF;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];
 
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main() {
    //cout.precision(10);
    int q;
    cin >> q;
    while(q--) {
        NG = false;
        int n;
        //cin >> n;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) {
            while(!que[i].empty()) que[i].pop();
        }
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        for(int i = 1; i <= n; i++) {
            que[a[i]].push(i);
        }
        for(int i = 1; i <= n; i++) {
            if(que[b[i]].empty()) {
                NG = true;
                //cerr << i << " " << b[i] << endl;
            }
            else {
                indexes[i] = que[b[i]].front();
                invindexes[indexes[i]] = i;
                que[b[i]].pop();
            }
        }
        if(NG) {
            printf("NO\n");
            continue;
        }
        /*
        for(int i = 1; i <= n; i++) cerr << indexes[i] << " ";
        cerr << endl;
        for(int i = 1; i <= n; i++) cerr << invindexes[i] << " ";
        cerr << endl;
        */
        vector<i_i> v(n);
        for(int i = 1; i <= n; i++) {
            v[i-1].first = -a[i];
            v[i-1].second = i;
        }
        sort(v.begin(), v.end());
        SegmentTree seg(n + 1);
        for(int i = 0; i < v.size(); i++) {
            int index = v[i].second;
            if(seg.getmin(index + 1, n + 1) < invindexes[index]) NG = true;
            //cerr << i << " " << index << " " << seg.getmin(index + 1, n + 1) << endl;
            seg.update(index, invindexes[index]);
        }
        if(NG) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}