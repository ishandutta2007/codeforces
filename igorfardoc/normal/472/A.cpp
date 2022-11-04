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
    int n;
    cin >> n;
    int now = n / 2;
    while(true) {
        if((now % 2 == 0 || now % 3 == 0) && ((n - now) % 3 == 0 || (n - now) % 2 == 0)) {
            cout << now << ' ' << n - now;
            return 0;
        }
        now++;
    }
}