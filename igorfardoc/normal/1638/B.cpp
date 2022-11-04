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
        int a = -1;
        int b = -1;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if(val & 1) {
                if(val < a) ok = false;
                a = val;
            } else {
                if(val < b) ok = false;
                b = val;
            }
        }
        if(ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}