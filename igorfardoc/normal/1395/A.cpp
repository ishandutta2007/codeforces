#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
bool good(vi a) {
    int am = 0;
    for(auto el : a) {
        am += el % 2;
    }
    return am < 2;
}


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
        vi a(4);
        for(int i = 0; i < 4; i++) {
            cin >> a[i];
        }
        bool ok = false;
        ok = ok || good(a);
        for(int i = 0; i < 2; i++) {
            bool can = true;
            for(int j = 0; j < 3; j++) {
                if(a[j] == 0) {
                    can = false;
                    break;
                }
            }
            if(!can) {
                break;
            }
            for(int j = 0; j < 3; j++) {
                --a[j];
            }
            a[3] += 3;
            ok = ok || good(a);
        }
        if(ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}