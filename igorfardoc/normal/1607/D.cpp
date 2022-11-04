#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
        }
        string s;
        cin >> s;
        vi now(n);
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B') {
                if(a[i] < 0) {
                    ok = false;
                    break;
                }
                now[min(a[i], n - 1)]++;
            }
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        int now1 = 0;
        for(int i = 0; i < n; i++) {
            now1 += now[i];
            if(now1 > i + 1) {
                ok = false;
                break;
            }
        }
        now.assign(n, 0);

        for(int i = 0; i < n; i++) {
            if(s[i] == 'R') {
                if(a[i] > n - 1) {
                    ok = false;
                    break;
                }
                now[max(a[i], 0)]++;
            }
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        now1 = 0;
        for(int i = n - 1; i >= 0; i--) {
            now1 += now[i];
            if(now1 > n - i) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}