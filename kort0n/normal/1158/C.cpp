#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree(int k) {
        int sz = k;
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
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};
set<int> rest;
vector<int> Next;
SegmentTree seg(1);
int N;

void f(int nowindex) {
    if(seg.getmax(nowindex, nowindex + 1) != 0) return;
    if(Next[nowindex] != N + 1 && Next[nowindex] != -1) f(Next[nowindex]);
    auto itr = rest.end();
    itr--;
    seg.update(nowindex, *itr);
    rest.erase(itr);
}

bool check() {
    for(int i = 1; i <= N; i++) {
        if(Next[i] == -1) continue;
        //cerr << i << " " << seg.getmax(i + 1, Next[i]) << endl;
        if(seg.getmax(i + 1, Next[i]) > seg.getmax(i, i + 1)) return false;
        if(Next[i] <= N && (seg.getmax(i, i + 1) > seg.getmax(Next[i], Next[i] + 1))) return false;
    }
    return true;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> N;
        rest.clear();
        for(int i = 1; i <= N; i++) rest.insert(i);
        Next.resize(N + 1);
        for(int i = 1; i <= N; i++) cin >> Next[i];
        int nowindex = 1;
        seg = SegmentTree(N + 1);
        while(true) {
            f(nowindex);
            //cerr << nowindex << " " << seg.getmax(nowindex, nowindex + 1) << endl;
            if(nowindex == N) break;
            nowindex++;
        }
        if(check()) {
            for(int i = 1; i <= N; i++) {
                cout << seg.getmax(i, i + 1);
                if(i < N) cout << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}