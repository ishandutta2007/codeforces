#include<bits/stdc++.h>
#define reg register
#define ll long long
using namespace std;
inline int read() {
    int x=0,f=1,c=getchar();
    for (;c< 48;c=getchar()) if (c=='-') f=0;
    for (;c>=48;c=getchar()) x = x*10 + c-'0';
    return f?x:-x;
}
int main() {
    map <int,int> mp[10];
    for (int i = 2; i <= 9; ++ i) {
        int x = i;
        for (int j = 2; j * j <= x; ++ j) {
            if (x % j == 0) {
                while (x % j == 0) {
                    mp[i][j] ++;
                    x /= j;
                }
            }
        }
        if (x > 1) {
            mp[i][x] ++;
        }
    }
    int n = read();
    string a; cin >> a;
    map <int,int> tot;
    for (int i=0; i<n; ++ i) {
        if (a[i] >= '2') for (char c = '2'; c<=a[i]; ++ c) for (auto p:mp[c - '0']) tot[p.first] += p.second;
    }
    string ans;
    if (tot[7]) ans += string(tot[7], '7');
    if (tot[5]) ans += string(tot[5] - tot[7], '5');
    for (int i = 0; i < ans.size(); ++ i) {
        for (char c='2'; c<=ans[i]; ++ c) for (auto p:mp[c - '0']) tot[p.first] -= p.second;
    }
    if (tot[3]) ans += string(tot[3], '3');
    if (tot[2]) ans += string(tot[2] - tot[3], '2');
    cout << ans << endl;
    return 0;
}