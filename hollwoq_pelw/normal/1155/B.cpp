#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, c=0;
    string s;
    cin >> n >> s;
    for (int i = 0; i <= n-11; i++) c += s[i] == '8';
    if (c > (n-10)/2) cout << "YES";
    else cout << "NO";
    return 0;
}