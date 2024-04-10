#include <bits/stdc++.h>
using namespace std;
int d(char a, char b){
    int x = a-'A', y = b-'A';
    return min(abs(x-y), 26-abs(x-y));
}
int sol(string a){
    string b = "ACTG";
    int ans = 0;
    for (int i = 0; i < 4; i++) ans += d(a[i],b[i]);
    return ans;
}
int main(){
    int n, ans = INT_MAX;
    string s;
    cin >> n >> s;
    //cout << d('Z','A');
    for (int i = 0; i <= n-4; i++){
        string a = s.substr(i, 4);
        ans = min(ans, sol(a));
    }
    cout << ans;
    return 0;
}