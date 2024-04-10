#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segTree { // a, b, c, ab, bc, abc
    vector<int> nums[6];
    vector<int> tot[3];
    int g = 1;
    void upd_sum(int i, int f, int t, int n, int lx, int rx) {
        if(lx > i || rx <= i) return;
        if(rx - lx == 1) {
            tot[f][n]--;
            tot[t][n]++;
            return;
        }
        int mid = (lx + rx)/2;
        upd_sum(i, f, t, 2*n+1, lx, mid);
        upd_sum(i, f, t, 2*n+2, mid, rx);
        tot[f][n] = tot[f][2*n+1] + tot[f][2*n+2];
        tot[t][n] = tot[t][2*n+1] + tot[t][2*n+2];
        return;
    }
    int upd_get(int i, int x, int n, int lx, int rx) {
        if(x < 3) return tot[x][n];
        if(lx > i || rx <= i) return nums[x][n];
        if(rx - lx == 1) return 0;
        int mid = (lx + rx)/2;
        if(x < 5) {
            int le1 = upd_get(i, x-3, 2*n+1, lx, mid);
            int ri1 = upd_get(i, x, 2*n+2, mid, rx);
            int le2 = upd_get(i, x, 2*n+1, lx, mid);
            int ri2 = upd_get(i, x-2, 2*n+2, mid, rx);
            return nums[x][n] = min(le1 + ri1, le2 + ri2);
        }
        // a, abc
        int le1 = upd_get(i, 0, 2*n+1, lx, mid);
        int ri1 = upd_get(i, 5, 2*n+2, mid, rx);
        // ab, bc
        int le2 = upd_get(i, 3, 2*n+1, lx, mid);
        int ri2 = upd_get(i, 4, 2*n+2, mid, rx);
        // abc, c
        int le3 = upd_get(i, 5, 2*n+1, lx, mid);
        int ri3 = upd_get(i, 2, 2*n+2, mid, rx);
        return nums[x][n] = min(min(le1 + ri1, le2 + ri2), le3 + ri3);
    }
    int upd(int i, int f, int t) {
        upd_sum(i, f, t, 0, 0, g);
        return upd_get(i, 5, 0, 0, g);
    }
    void init(int n) {
        while(g < n) g *= 2;
        for(int i = 0; i < 6; i++) {
            nums[i].resize(2*g);
            if(i < 3) tot[i].resize(2*g);
        }
        for(int i = g-1; i < 2*g-1; i++) tot[0][i] = 1;
        for(int i = g-2; i >= 0; i--) tot[0][i] = tot[0][2*i+1] + tot[0][2*i+2];
        for(int i = 0; i < 2*g-1; i++) {
            for(int j = 0; j < 6; j++) {
                if(j == 0) nums[j][i] = tot[j][i];
                else nums[j][i] = 0;
            }
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    segTree st;
    st.init(n);
    for(int i = 0; i < n; i++) {
        st.upd(i, 0, s.at(i) - 'a'); 
    }
    while(q--) {
        int p;
        char ch;
        cin >> p >> ch;
        p--;
        cout << st.upd(p, s[p]-'a', ch-'a') << '\n';
        s[p] = ch;
    }
}