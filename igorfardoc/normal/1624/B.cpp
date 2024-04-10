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
        int a, b, c;
        cin >> a >> b >> c;
        bool ok = false;
        if(b + b - a > 0 && (b + (b - a)) % c == 0) {
            ok = true;
        } else if((a + c) % 2 == 0 && ((a + c) / 2) % b == 0) {
            ok = true;
        } else if(b - (c - b) > 0 && (b - (c - b)) % a == 0) {
            ok = true;
        }
        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}