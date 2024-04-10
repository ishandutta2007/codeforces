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
        if(n == 1) {
            cout << "FastestFinger" << '\n';
            continue;
        }
        if(n == 2) {
            cout << "Ashishgup" << '\n';
            continue;
        }
        int here = 1;
        while(n / here % 2 == 0) {
            here *= 2;
        }
        if(n == here) {
            cout << "FastestFinger" << '\n';
            continue;
        }
        if(here == 2) {
            bool pr = true;
            for(int i = 2; i * i <= n / here; i++) {
                if(n / here % i == 0) {
                    pr = false;
                    break;
                }
            }
            if(pr) {
                cout << "FastestFinger" << '\n';
                continue;
            }
        }
        cout << "Ashishgup" << '\n';
    }

}