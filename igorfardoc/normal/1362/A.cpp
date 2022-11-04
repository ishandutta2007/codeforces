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
        ll a, b;
        cin >> a >> b;
        if(a > b) {
            swap(a, b);
        }
        if(b % a != 0) {
            cout << -1 << '\n';
            continue;
        }
        ll now = b / a;
        int it = 0;
        while(now % 2 == 0) {
            now /= 2;
            ++it;
        }
        if(now != 1) {
            cout << -1 << '\n';
            continue;
        }
        if(it == 0) {
            cout << 0 << '\n';
            continue;
        }
        cout << (it - 1) / 3 + 1 << '\n';
    }   
}