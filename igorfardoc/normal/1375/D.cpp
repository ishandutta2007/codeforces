#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi a;

int mex() {
    vi b(a.size() + 1, 0);
    for(int i = 0; i < a.size(); i++) {
        b[a[i]]++;
    }
    for(int i = 0; i <= a.size(); i++) {
        if(b[i] == 0) {
            return i;
        }
    }
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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vi ans;
        for(int i = 0; i < 2 * n; i++) {
            int now = mex();
            if(now == n) {
                for(int i = 0; i < n; i++) {
                    if(a[i] != i) {
                        a[i] = now;
                        ans.push_back(i);
                        break;
                    }
                }
                continue;
            }
            a[min(n - 1, now)] = now;
            ans.push_back(min(n - 1, now));
        }
        cout << ans.size() << '\n';
        for(auto& el : ans) {
            cout << el + 1 << ' ';
        }
        cout << '\n';
    }
}