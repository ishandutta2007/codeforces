#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    string s;
    cin >> s;

    int b = 0;
    ll ans = 0;
    priority_queue <pii> q;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') ++b;
        if (s[i] == ')') --b;
        if (s[i] == '?')
        {
            ll x, y;
            cin >> x >> y;
            s[i] = ')';
            --b;
            ans += y;
            q.push(mp(y - x, i));
        }
        if (b < 0)
        {
            if (q.empty()) break;
            pii tmp = q.top();
            q.pop();
            ans -= tmp.first;
            b += 2;
            s[tmp.second] = '(';
        }
    }

    if (b) cout << "-1";
    else cout << ans << "\n" << s;

}