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
        string s;
        cin >> s;
        int amR = 0;
        int amS = 0;
        int amP = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'R') {
                ++amR;
            } else if(s[i] == 'S') {
                ++amS;
            } else {
                ++amP;
            }
        }
        char c = 'R';
        int max1 = max(max(amR, amS), amP);
        if(amP == max1) {
            c = 'S';
        } else if(amR == max1) {
            c = 'P';
        }
        for(int i = 0; i < s.size(); i++) {
            cout << c;
        }
        cout << '\n';
    }
}