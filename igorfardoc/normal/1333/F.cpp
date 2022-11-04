#include<bits/stdc++.h>
#define MAX 500000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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
    vi pr;
    for(int i = 2; i <= MAX; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAX; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
    lp[1] = 1;
    int n;
    cin >> n;
    vi a(n);
    for(int i = 1; i <= n; i++) {
        a[i - 1] = i / lp[i];
    }
    sort(a.begin(), a.end());
    vi ans(n + 1);
    for(int i = 0; i < n; i++) {
        ans[i + 1] = a[i];
    }
    for(int i = 2; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}