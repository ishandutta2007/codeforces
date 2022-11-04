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
        string s;
        cin >> s;
        vi ans;
        int am0 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                ++am0;
            }
        }
        for(int i = 0; i < n; i++) {
            if(i < am0 && s[i] == '1') {
                ans.push_back(i);
            } else if(i >= am0 && s[i] == '0') {
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) {
            cout << 0 << '\n';
        } else {
            cout << "1\n" << ans.size() << ' ';
            for(auto& el : ans) {
                cout << el + 1 << ' ';
            }
            cout << '\n';
        }
    }
}