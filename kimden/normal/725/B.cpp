#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    char c = s[s.length() - 1];
    s = s.substr(0, s.length() - 1);
    ll n = atoll(s.c_str());
    ll p = 0;
    switch(c){
    case 'f':
        p = 1;
        break;
    case 'e':
        p = 2;
        break;
    case 'd':
        p = 3;
        break;
    case 'a':
        p = 4;
        break;
    case 'b':
        p = 5;
        break;
    case 'c':
        p = 6;
        break;
    }
    p += ((n - 1) / 4) * 16;
    if(n%2 == 0){
        p += 7;
    }
    cout << p;
    return 0;
}