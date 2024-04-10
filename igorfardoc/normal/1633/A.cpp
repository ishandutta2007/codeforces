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
        if(n % 7 == 0) {
            cout << n << '\n';
            continue;
        }
        for(int last = 0; last < 10; last++) {
            int now = n / 10;
            now = now * 10 + last;
            if(now % 7 == 0) {
                cout << now << '\n';
                break;
            }
        }
    }
}