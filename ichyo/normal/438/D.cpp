#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef long long LL;
struct SegTree{
    int n;
    vector<LL> sum;
    vector<int> maxd;
    vector<int> data;
    SegTree(const vector<int>& data_) {
        data = data_;
        n = data.size();
        sum.resize(4*n+10, 0);
        maxd.resize(4*n+10, 0);
        init(1, 0, n);
    }

    void init(int k, int l, int r) {
        if(r - l == 1) {
            sum[k] = maxd[k] = data[l];
        } else {
            int m = (l+r) / 2;
            init(2*k, l, m);
            init(2*k+1, m, r);
            sum[k] = sum[2*k] + sum[2*k+1];
            maxd[k] = max(maxd[2*k], maxd[2*k+1]);
        }
    }

    LL get_sum(int a, int b) {
        return get_sum(a, b, 1, 0, n);
    }

    LL get_sum(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a) {
            return 0;
        } else if(a <= l && r <= b) {
            return sum[k];
        } else {
            LL vl = get_sum(a, b, 2*k, l, (l+r)/2);
            LL vr = get_sum(a, b, 2*k+1, (l+r)/2, r);
            return vl + vr;
        }
    }

    void apply_mod(int a, int b, int x) {
        apply_mod(a, b, x, 1, 0, n);
    }
    void apply_mod(int a, int b, int x, int k, int l, int r) {
        if(b <= l || r <= a) return;
        if(maxd[k] < x) return; 
        if(l + 1 == r) {
            data[l] %= x;
            sum[k] = maxd[k] = data[l];
        } else {
            apply_mod(a, b, x, 2*k, l, (l+r)/2);
            apply_mod(a, b, x, 2*k +1, (l+r)/2, r);
            sum[k] = sum[2*k] + sum[2*k+1];
            maxd[k] = max(maxd[2*k], maxd[2*k+1]);
        }
    }

    void set_value(int k, int x) {
        set_value(k, x, 1, 0, n);
    }
    void set_value(int a, int x, int k, int l, int r) {
        if(l + 1 == r) {
            assert(l == a);
            data[a] = x;
            sum[k] = maxd[k] = data[a];
        } else {
            int m = (l + r) / 2;
            if(l <= a && a < m) {
                set_value(a, x, 2*k, l, m);
            } else {
                set_value(a, x, 2*k+1, m, r);
            }
            sum[k] = sum[2*k] + sum[2*k+1];
            maxd[k] = max(maxd[2*k], maxd[2*k+1]);
        }
    }
};

int main(){
    int n, m;
    while(cin >> n >> m) {
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        SegTree tree(a);
        REP(i, m) {
            int t;
            cin >> t;
            if(t == 1) {
                int a, b;
                cin >> a >> b;
                cout << tree.get_sum(a-1, b) << endl;
            } else if(t == 2) {
                int a, b, x;
                cin >> a >> b >> x;
                tree.apply_mod(a-1, b, x);
            } else {
                int a, x;
                cin >> a >> x;
                tree.set_value(a-1, x);
            }
        }
    }
    return 0;
}