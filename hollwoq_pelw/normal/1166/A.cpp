#include <bits/stdc++.h>
using namespace std;

int c[26];

int get(int n){
    if (n%2==0) return n/2*(n/2-1);
    else return (n/2)*(n/2);
}

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        c[s[0]-'a'] ++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) ans += get(c[i]);
    cout << ans;
}