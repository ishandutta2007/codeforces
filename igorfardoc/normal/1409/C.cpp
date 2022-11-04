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
        int n, x, y;
        cin >> n >> x >> y;
        vi a;
        a.push_back(x);
        a.push_back(y);
        for(int d = 1;; d++) {
            //cout << d << endl;
            if((y - x) % d != 0) {
                continue;
            }
            if((y - x) / d - 1 > n - 2) {
                continue;
            }
            for(int i = x + d; i < y; i+=d) {
                a.push_back(i);
            }
            int min1 = x - d;
            while(a.size() != n && min1 > 0) {
                a.push_back(min1);
                min1 -= d;
            }
            int max1 = y + d;
            while(a.size() != n) {
                a.push_back(max1);
                max1 += d;
            }
            for(auto& el : a) {
                cout << el << ' ';
            }
            break;
        }
        cout << '\n';
    }
}