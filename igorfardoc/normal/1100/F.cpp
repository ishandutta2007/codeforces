#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
 
int basis[22];
int d = 22;
int sz = 0;
 
void add(int mask) {
    for (int i = d - 1; i >= 0; i--) {
        if ((mask & (1 << i)) == 0) continue;
 
        if (!basis[i]) {
            basis[i] = mask;
            ++sz;
            return;
        }
 
        mask ^= basis[i];
    }
}
 
bool check(int mask) {
    for (int i = d - 1; i >= 0; i--) {
        if ((mask & 1ll << i) == 0) continue; // continue if i != f(mask)
 
        if (!basis[i]) return false;
 
        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
    return true;
}

int get_max() {
    int res = 0;
    for(int i = d - 1; i >= 0; i--) {
        res = max(res, res ^ basis[i]);
    }
    return res;
}
 
void clear_basis() {
    sz = 0;
    for(int i = 0; i < d; i++) {
        basis[i] = 0;
    }
}
 
int main()
{
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    vector<array<ll, 3>> qu(q);
    for(int i = 0; i < q; i++) {
        cin >> qu[i][0] >> qu[i][1];
        qu[i][2] = i;
        --qu[i][0];
        --qu[i][1];
    }
    sort(qu.rbegin(), qu.rend());
    vi nxt(n), bef(n);
    for(int i = 0; i < n; i++) {
        nxt[i] = i + 1;
        bef[i] = i - 1;
    }
    vi ans(q);
    for(int i = 0; i < q; i++) {
        int now = qu[i][0];
        clear_basis();
        while(now <= qu[i][1]) {
            int pr = sz;
            add(a[now]);
            if(sz == pr) {
                if(nxt[now] != n) {
                    bef[nxt[now]] = bef[now];
                }
                if(bef[now] != -1) {
                    nxt[bef[now]] = nxt[now];
                }
            }
            if(sz == 22) break;
            now = nxt[now];
        }
        ans[qu[i][2]] = get_max();
    }
    for(const auto& el : ans) {
        cout << el << '\n';
    }
}