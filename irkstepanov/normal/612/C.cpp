#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

bool corr(char a, char b)
{
    if (a == '<' && b == '>') {
        return true;
    }
    if (a == '[' && b == ']') {
        return true;
    }
    if (a == '{' && b == '}') {
        return true;
    }
    if (a == '(' && b == ')') {
        return true;
    }
    return false;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    string s;
    cin >> s;

    stack<char> m;

    int n = sz(s);
    int ans = 0;

    forn(i, n) {
        if (s[i] == '<' || s[i] == '[' || s[i] == '{' || s[i] == '(') {
            m.push(s[i]);
            continue;
        }
        if (m.empty()) {
            cout << "Impossible\n";
            return 0;
        }
        if (!corr(m.top(), s[i])) {
            ++ans;
        }
        m.pop();
    }

    if (!m.empty()) {
        cout << "Impossible\n";
        return 0;
    }
    cout << ans << "\n";

}