#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree() {
        int sz = 100500;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
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
    int n, m;
    cin >> n >> m;
    SegmentTree seg;
    int now = 1;
    for(int i = 1; i <= m; i++){
        int a;
        cin >> a;
        int val = seg.getmin(a, a+1);
        seg.update(a, val + 1);
        val = seg.getmin(1, n + 1);
        if(val == now) {
            now++;
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
    return 0;
}