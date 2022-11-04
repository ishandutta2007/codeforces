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
        vector<bool> was(1024, false);
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            was[a] = true;
        }
        bool ok1 = false;
        for(int i = 1; i <= 1023; i++) {
            auto was1 = was;
            bool ok = true;
            for(int j = 0; j <= 1023; j++) {
                if(was[j] && !was1[j ^ i]) {
                    ok = false;
                    break;
                }
                if(was[j]) {
                    was1[j ^ i] = false;
                }
            }
            if(ok) {
                ok1 = true;
                cout << i << '\n';
                break;
            }
        }
        if(!ok1) {
            cout << -1 << '\n';
        }
    }
}