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
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s = "";
        for(int i = 0; i < 50; i++) {
            s += 'a';
        }
        cout << s << '\n';
        for(int i = 0; i < n; i++) {
            char other = 'a';
            string s1 = "";
            if(s[a[i]] == other) {
                other = 'b';
            }
            for(int j = 0; j < a[i]; j++) {
                s1 += s[j];
            }
            for(int j = 0; j < 50 - a[i]; j++) {
                s1 += other;
            }
            cout << s1 << '\n';
            s = s1;
        }
    }

}