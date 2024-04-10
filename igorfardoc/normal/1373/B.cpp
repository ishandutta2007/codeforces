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
        string s;
        cin >> s;
        int am0 = 0;
        int am1 = 0;
        for(auto& el : s) {
            if(el == '0') {
                ++am0;
            } else {
                ++am1;
            }
        }
        if(min(am0, am1) % 2 == 0) {
            cout << "NET\n";
        } else {
            cout << "DA\n";
        }
    }
}