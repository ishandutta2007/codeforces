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
    if(s[0] >= 'a'){
        s[0] += 'A'-'a';
    }
    cout << s;
    return 0;
}