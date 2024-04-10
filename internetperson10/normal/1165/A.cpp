#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y, ans=0;
    string s;
    cin >> n >> x >> y >> s;
    for(int a=1; a<=x; a++) {
        if(a-1==y) {
            if(s.at(s.size()-a)=='0') ans++;
        }
        else if(s.at(s.size()-a)=='1') ans++;
    }
    cout << ans;
}