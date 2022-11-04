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
        set<int> a;
        for(int i = 0; i < 2 * n; i++) {
            int c;
            cin >> c;
            if(a.find(c) != a.end()) {
                continue;
            }
            cout << c << ' ';
            a.insert(c);
        }
        cout << '\n';
    }
}