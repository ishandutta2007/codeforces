#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
string mask(int a) {
    string ans = "";
    string s = to_string(a);
    for(auto x: s) if(x == '4' || x == '7') ans += x;
    return ans;
}
int main() {
    int a;
    string b;
    cin >> a >> b;
    for(int i = a + 1; i <= 12261226; i++) if(mask(i) == b) {
        cout << i << '\n';
        return 0;
    }
}