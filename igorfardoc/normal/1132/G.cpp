#include<bits/stdc++.h>
#define int ll
#define maxn 1000000
#define inf 1000000000000000000ll
#define left left1
#define right right1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int t[maxn * 4 + 7], lp[maxn * 4 + 7];

void update(int now, int l, int r, int l1, int r1, int val) {
    if(l > r1 || l1 > r) return;
    if(l1 <= l && r <= r1) {
        t[now] += val;
        lp[now] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(now * 2, l, mid, l1, r1, val);
    update(now * 2 + 1, mid + 1, r, l1, r1, val);
    t[now] = max(t[now * 2], t[now * 2 + 1]) + lp[now];
}

int get(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) return -inf;
    if(l1 <= l && r <= r1) return t[now];
    int mid = (l + r) / 2;
    return max(get(now * 2, l, mid, l1, r1), get(now * 2 + 1, mid + 1, r, l1, r1)) + lp[now];
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi left(n, -1);
    vi right(n, n);
    vi st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.back()] <= a[i]) {
            st.pop_back();
        }
        if(!st.empty()) right[i] = st.back();
        st.push_back(i);
    }
    st.clear();
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.back()] < a[i]) {
            st.pop_back();
        }
        if(!st.empty()) left[i] = st.back();
        st.push_back(i);
    }
    for(int i = n - 1; i > n - 1 - k; i--) {
        if(right[i] == n) {
            update(1, 0, n - 1, i, i, 1);
        } else {
            int val = get(1, 0, n - 1, right[i], right[i]);
            update(1, 0, n - 1, i, i, val + 1);
        }
    }
    vi ans;
    for(int i = n - k; i >= 0; i--) {
        ans.push_back(get(1, 0, n - 1, i, i + k - 1));
        if(i == 0) continue;
        int lf = max(left[i + k - 1] + 1, i);
        update(1, 0, n - 1, lf, i + k - 1, -1);
        int val = 0;
        if(right[i - 1] < i + k - 1) {
            val = get(1, 0, n - 1, right[i - 1], right[i - 1]);
        }
        update(1, 0, n - 1, i - 1, i - 1, val + 1);
    }
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
}