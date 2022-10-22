#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int a[10];
    for (int i = 0; i < 9; i++) cin >> a[i+1];
    int l = 0;
    while(l < n){
        if (s[l]-'0' < a[s[l]-'0']) break;
        l ++;
    }
    int r = l;
    while(r < n){
        s[r++] = (char) a[s[r]-'0']+48;
        if (s[r]-'0' > a[s[r]-'0']) break;
    }
    cout << s;
    return 0;
}