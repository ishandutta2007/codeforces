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
    string s;
    cin >> s;
    set<char> s1;
    for(int i = 0; i < n; i++) {
        if(s[i] < 'a') {
            s[i] = s[i] - 'A' + 'a';
        }
        s1.insert(s[i]);
    }
    if(s1.size() == 26) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}