#include<bits/stdc++.h>
#define MAX 5000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int amountdiv[MAX + 1];
ll ans[MAX + 1];
vi pr;
int lp[MAX + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    for(int i = 2; i <= MAX; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && i * pr[j] <= MAX && pr[j] <= lp[i]; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j * j <= a[i]; ++j) {
            if(a[i] % j == 0) {
                ++amountdiv[j];
                if(a[i] / j != j) {
                    ++amountdiv[a[i] / j];
                }
            }
        }
    }
    for(int i = 1; i <= MAX; i++) {
        for(int j = 0; j < pr.size() && (ll)i * pr[j] <= MAX; ++j) {
            int need = i * pr[j];
            ans[need] = max(ans[need], ans[i] + (ll)(amountdiv[i] - amountdiv[need]) * i);
        }
    }
    ll res = 0;
    for(int i = 1; i <= MAX; i++) {
        res = max(res, ans[i] + (ll)amountdiv[i] * i);
    }
    cout << res;
}