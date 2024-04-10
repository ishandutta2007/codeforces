#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map <pair <int, int>, int> cnt;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    cnt[{0, 0}]++;
    int x = 0, y = 0;
    for(auto c : s){
        if(c == 'U') y++;
        else if(c == 'D') y--;
        else if(c == 'L') x--;
        else x++;
        res += cnt[{x, y}];
        cnt[{x, y}]++;
    }
    cout << res << "\n";
    return 0;
}