#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int t = 0, n = 0;
    for (char c:s) {t+=(c=='a'); n++;}
    //cout << t << ' ' << n;
    cout << min(n, 2*t-1);
}