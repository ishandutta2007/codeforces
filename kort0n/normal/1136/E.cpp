#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 100500;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]);
        }
    }
    // hannkaikukann 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};


#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n;
ll a[100500];
ll k[100500];
ll delta[100500];
set<ll> robust;
SegmentTree seg[2];
void update(ll i) {
    seg[0].update(i, delta[i] * (n - i));
    seg[1].update(i, delta[i]);
}

void add(ll index, ll val) {
    //cerr << "CALLED " << index << val << " " << delta[index] << endl;
    delta[index] -= val;
    if(index == n) {
        update(index);
        return;
    }
    if(delta[index] > k[index]) {
        update(index);
        robust.insert(index);
        return;
    }
    if(delta[index] == k[index]) {
        update(index);
        robust.erase(index);
        return;
    }
    ll eval = k[index] - delta[index];
    delta[index] = k[index];
    update(index);
    robust.erase(index);
    auto NEXT = robust.lower_bound(index);
    if(*NEXT == n) return;
    add(*NEXT, eval);
}

int main() {
    //cout.precision(10);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i < n; i++) {
        cin >> k[i];
        delta[i] = a[i+1] - a[i];
        if(delta[i] > k[i]) robust.insert(i);
        seg[0].update(i, delta[i] * (n - i));
        seg[1].update(i, delta[i]);
    }
    robust.insert(n);
    k[n] = -1e17;
    int q;
    cin >> q;
    while(q--) {
        /*
        cerr << "query " << q << endl;
        for(auto itr = robust.begin(); itr != robust.end(); itr++) {
            cerr << *itr << " ";
        }
        cerr << endl;
        int before = a[1];
        cerr << before << " ";
        for(int i = 1; i < n; i++) {
            before += delta[i];
            cerr << before << " ";
        }
        cerr << endl;
        */
        char query;
        cin >> query;
        if(query == 's') {
            ll l, r;
            cin >> l >> r;
            ll base = a[1] + seg[1].getsum(1, l);
            base *= (r - l + 1);
            ll ans = base + seg[0].getsum(l, r) - seg[1].getsum(l, r) * (n - r);
            //cout << "ANSWER: " << ans << endl;
            cout << ans << endl;
            continue;
        }
        ll i, x;
        cin >> i >> x;
        if(i == 1) {
            a[1] += x;
            add(1, x);
            //delta[1] -= x;
            //update(1);
            continue;
        }
        if(i == n) {
            delta[i - 1] += x;
            update(i - 1);
            robust.insert(i - 1);
            continue;
        }
        delta[i - 1] += x;
        update(i - 1);
        robust.insert(i - 1);
        add(i, x);
    }
    return 0;
}