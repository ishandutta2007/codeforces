#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int cur = 0, m = 0;
    for (char c:s){
        if (c == '(') cur ++;
        else cur --;
        m = min(cur, m);
    }
    if (m < -1 || cur != 0) cout << "No";
    else cout << "Yes";
}