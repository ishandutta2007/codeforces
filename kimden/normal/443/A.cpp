#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

map<char, bool> mp;

int main() {
    ios_base::sync_with_stdio(false);
    char c = ' ';
    while(c !='}'){
        scanf("%c", &c);
        if(c >= 'a' && c <= 'z'){
            mp[c] = true;
        }
    }
    cout << mp.size();
    return 0;
}