#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

char tolower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return char(c - 'A' + 'a');
    }
    return c;
}

void f(string& s) {
    string ans = "";
    for (int i = 0; i < sz(s); ++i) {
        if (isalpha(s[i])) {
            ans += tolower(s[i]);
        }
    }
    s = ans;
}
 
int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b, c;
    cin >> a >> b >> c;
    f(a), f(b), f(c);

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        f(s);
        if (s == a + b + c || s == a + c + b || s == b + a + c || s == b + c + a || s == c + a + b || s == c + b + a) {
            cout << "ACC\n";
        } else {
            cout << "WA\n";
        }
    }

}