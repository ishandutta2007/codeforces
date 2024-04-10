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
        vi a(2 * n);
        for(int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        vi a0, a1;
        for(int i = 0; i < 2 * n; i++) {
            if(a[i] % 2 == 0) {
                a0.push_back(i + 1);
            } else {
                a1.push_back(i + 1);
            }
        }
        if(a0.size() % 2 == 1) {
            a1.pop_back();
            a0.pop_back();
        } else {
            if(a0.empty()) {
                a1.pop_back();
                a1.pop_back();
            } else {
                a0.pop_back();
                a0.pop_back();
            }
        }
        for(int i = 0; i < a0.size(); i+=2) {
            cout << a0[i] << ' ' << a0[i + 1] << '\n';
        }
        for(int i = 0; i < a1.size(); i+=2) {
            cout << a1[i] << ' ' << a1[i + 1] << '\n';
        }
    }
}