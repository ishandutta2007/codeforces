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
        string s, t;
        cin >> s;
        cin >> t;
        vi ans;
        int now1 = 1; // i
        int now2 = 0; // adding
        int am = 0;
        int fir = (s[0] - '0');
        for(int i = n - 1; i >= 0; i--) {
            int here = (s[(i - now2) * now1] - '0');
            if(am % 2 == 1) {
                here = 1 - here;
            }
            //cout << here << ' ' << fir << endl;
            if(here == (t[i] - '0')) {
                continue;
            }
            ++am;
            if(fir != here) {
                ans.push_back(1);
                fir = 1 - fir;
            }
            ans.push_back(i + 1);
            fir = 1 - here;
            now1 *= -1;
            now2 = i - now2;
        }
        cout << ans.size() << '\n';
        for(auto el : ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}