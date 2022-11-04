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
    ll k;
    cin >> k;
    string s = "codeforces";
    for(int i = 1;; i++) {
        ll now = 1;
        ll prev = 1;
        for(int j = 0; j < 10; j++) {
            now *= i;
            prev *= (i - 1);
        }
        if(now >= k) {
            ll now1 = 1;
            for(int j = 0; j < 10; j++) {
                int here = i;
                if(now1 * prev >= k) {
                    here = i - 1;
                }
                now1 *= here;
                if(i != 1) {
                    prev /= (i - 1);
                }
                for(int k1 = 0; k1 < here; k1++) {
                    cout << s[j];
                }
            }
            break;
        }
    }
}