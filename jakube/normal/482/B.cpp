#include <bits/stdc++.h>
using namespace std;


class InvSegmentTree{
public:
    vector<long long> data;
    int N;
    InvSegmentTree(int n) : N(n) {
        
        data.assign(N*2, 0);
    }

    void update(int left, int right, int val) {
        left += N;
        right += N;

        while (left < right) {
            if (left & 1) data[left++] |= val;
            if (right & 1) data[--right] |= val;
            left >>= 1;
            right >>= 1;
        }
    }

    void res() {
        for (int i = 1; i < N; i++) {
            data[i<<1] |= data[i];
            data[i<<1|1] |= data[i];
        }

        for (int i = N-1; i > 0; i--) {
            data[i] = data[i<<1] & data[i<<1|1];
        }
    }

    long long query(int left, int right) {
        left += N;
        right += N;

        long long result = ~0LL;
        while (left < right) {
            if (left & 1) result &= data[left++];
            if (right & 1) result &= data[--right];
            left >>= 1;
            right >>= 1;
        }

        return result;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    
    InvSegmentTree st(n);

    vector<tuple<int, int, long long>> v(m);
    for (int i = 0; i < m; i++) {
        cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]);

        st.update(get<0>(v[i])-1, get<1>(v[i]), get<2>(v[i]));
    }
    st.res();

    for (int i = 0; i < m; i++) {
        if (st.query(get<0>(v[i])-1, get<1>(v[i])) != get<2>(v[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    for (int i = 0; i < n; i++) {
        cout << st.data[n+i] << " ";
    }
    cout << endl;




    

    return 0;
}