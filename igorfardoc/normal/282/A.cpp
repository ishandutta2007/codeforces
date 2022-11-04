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
    int n;
    cin >> n;
    int x = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s[1] == '+') {
            ++x;
        } else {
            --x;
        }
    }
    cout << x;
}