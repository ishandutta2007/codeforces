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
    string s;
    cin >> s;
    string a = "";
    for(int i = 0; i < s.size(); i+=2) {
        a += s[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i != a.size() - 1) {
            cout << '+';
        }
    }
}