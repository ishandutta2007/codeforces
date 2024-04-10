#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vi a;
ll ans = 0;

void rec1(vi& a, int mid) {
    int n = a.size();
    vi mx(n);
    int mxnow = 0;
    for(int i = mid + 1; i < n; i++) {
        mxnow = max(mxnow, a[i]);
        mx[i] = mxnow;
    }
    unordered_map<int, int> am;
    int now, now1;
    for(int i = mid + 1; i < n; i++) {
        if(am[a[i]] == 1) break;
        now = i;
        ++am[a[i]];
    }
    now1 = mid;
    mxnow = 0;
    for(int i = mid; i >= 0; i--) {
        ++am[a[i]];
        mxnow = max(mxnow, a[i]);
        while(now > mid && am[a[i]] > 1) {
            --am[a[now]];
            --now;
        }
        while(now1 < n - 1 && mx[now1 + 1] < mxnow) {
            ++now1;
        }
        //mxnow + 1 - (mid - i + 1) + mid
        //now - mid + mid + 1 - i == mxnow + 1
        if(now == mid) break;
        if(now1 == mid) continue;
        if(min(now, now1) == mxnow + i) ++ans;
    }
}

void rec(int l, int r) {
    if(l == r) {
        if(a[l] == 0) {
            ++ans;
        }
        return;
    }
    int mid = (l + r) / 2;
    {
        vi here;
        for(int i = l; i <= r; i++) {
            here.push_back(a[i]);
        }
        rec1(here, mid - l);
        reverse(here.begin(), here.end());
        rec1(here, r - mid - 1);
    }
    rec(l, mid);
    rec(mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    rec(0, n - 1);
    cout << ans;
}