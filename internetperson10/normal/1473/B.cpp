#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1, n;
    long long int w=0, x=0, y=0, z=0, ans=0;
    int a=0, b=0, c=0, d=0, e=0;
    bool sad = false;
    string s1, s2;
    cin >> t;
    while(t--) {
        sad = false;
        cin >> s1 >> s2;
        a = s1.size(); b = s2.size();
        c = a*b/(__gcd(a, b));
        for(int i = 0; i < c; i++) {
            if(s1.at(i%a) != s2.at(i%b)) sad = true;
        }
        if(sad) cout << -1 << '\n';
        else {
            for(int i = 0; i < c/a; i++) cout << s1;
            cout << '\n';
        }
    }
}