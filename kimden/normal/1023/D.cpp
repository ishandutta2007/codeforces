#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using itn = int;

vector<int> f;

void add(int idx, int val){
    while(idx <= f.size()){
        f[idx] += val;
        idx |= idx + 1;
    }
}

int getsum(int idx){
    int ans = 0;
    while(idx >= 0){
        ans += f[idx];
        idx &= idx + 1;
        --idx;
    }
    return ans;
}
const int MAXN = 1 << 18;
int tree[MAXN * 2], psh[MAXN];

void push(int idx){
    if(idx <= MAXN && psh[idx] != 0){
        if((idx << 1) < MAXN) {
            psh[idx << 1] = psh[idx];
            psh[(idx << 1) | 1] = psh[idx];
        }
        tree[idx << 1] = psh[idx];
        tree[(idx << 1) | 1] = psh[idx];
        psh[idx] = 0;
    }
}

void update(int idx, int l, int r, int tl, int tr, int val){
    if(tl > r || l > tr || tl > tr){
        return;
    }
    push(idx);
    if(l == tl && r == tr){
        tree[idx] = val;
        psh[idx] = val;
        return;
    }
    int mid = (l + r + 1) / 2;
    update(idx << 1, l, mid - 1, tl, min(tr, mid - 1), val);
    update((idx << 1) | 1, mid, r, max(tl, mid), tr, val);
    tree[idx] = max(tree[idx << 1], tree[(idx << 1) | 1]);
}

int where(int val){
    if(getsum((int)f.size() - 1) < val){
        return f.size();
    }
    if(getsum(0) >= val){
        return 0;
    }

    int cur = (1 << 17) - 1;
    int L = 0, R = (1 << 18);
    while(R - L > 1){
        int mid = (R + L) / 2 - 1;
        if(f[mid] < val){
            L = mid + 1;
            val -= f[mid];
        }else{
            R = mid + 1;
        }
    }
    return L;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    unordered_map<int, vector<int>> mp;
    f.resize((1 << 18), 0);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    int pos = -1;
    if(mp.count(q)){
        pos = mp[q][0];
    }else if(mp.count(0)){
        pos = mp[0][0];
    }else{
        cout << "NO" << endl;
        return 0;
    }

    if(mp.count(1)) {
        for (int j = 0; j < mp[1].size(); ++j) {
            add(mp[1][j], 1);
        }
    }
    update(1, 0, MAXN - 1, 0, n - 1, 1);
    for(int i = 2; i <= q; ++i){
        int cnt;
        if(!mp.count(i)){
            cnt = getsum(pos);
            int L = where(cnt) + (cnt == 0 ? 0 : 1);
            int R = min(n, where(cnt + 1)) - 1;
            update(1, 0, MAXN - 1, L, R, i);
        }else{
            cnt = getsum(mp[i][0]);
            for(int j = 1; j < mp[i].size(); ++j){
                if(getsum(mp[i][j]) != cnt){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            int L = where(cnt) + (cnt == 0 ? 0 : 1);
            int R = min(n, where(cnt + 1)) - 1;
            update(1, 0, MAXN - 1, L, R, i);
            for(int j = 0; j < mp[i].size(); ++j){
                add(mp[i][j], 1);
            }
        }
    }
    for(int i = 1; i < MAXN; ++i){
        push(i);
    }
    cout << "YES" << endl;
    for(int i = MAXN; i < MAXN + n; ++i){
        if(i > MAXN){
            cout << " ";
        }
        cout << tree[i];
    }
    cout << endl;
}