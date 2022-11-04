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
        int am2 = 0;
        int am3 = 0;
        while(n % 2 == 0) {
            ++am2;
            n /= 2;
        }
        while(n % 3 == 0) {
            ++am3;
            n /= 3;
        }
        if(n != 1 || am2 > am3) {
            cout << -1 << '\n';
            continue;
        }
        cout << 2 * am3 - am2 << '\n';
    }
}