#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{
//    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    bool ans = false;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            ans = true;
            break;
        }
    }
    cout << (ans ? "YES" : "NO");
    return 0;
}