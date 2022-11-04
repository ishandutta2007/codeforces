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
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    while(t--) {
        string snew = s;
        int i = 0;
        while(i < n) {
            if(i == n - 1) {
                snew[i] = s[i];
                ++i;
                continue;
            }
            if(s[i] == 'B' && s[i + 1] == 'G') {
                snew[i] = 'G';
                snew[i + 1] = 'B';
                i += 1;
            } else {
                snew[i] = s[i];
            }
            ++i;
        }
        s = snew;
    }
    cout << s;
}