#include <bits/stdc++.h>
 
using namespace std;
 
const int M = (int)(2e6 + 239);
 
int pref[M], c;
 
string solve_palindrome(const string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}
 
void solve()
{
    string t;
    cin >> t;
    int l = 0;
    while (l < (int)t.size() - l - 1)
    {
        if (t[l] != t[(int)t.size() - l - 1])
            break;
        l++;
    }
    if (l > 0)
        cout << t.substr(0, l);
    if ((int)t.size() > 2 * l)
    {
        string s = t.substr(l, (int)t.size() - 2 * l);
        string a = solve_palindrome(s);
        reverse(s.begin(), s.end());
        string b = solve_palindrome(s);
        if ((int)a.size() < (int)b.size())
            swap(a, b);
        cout << a;
    }
    if (l > 0)
        cout << t.substr((int)t.size() - l, l);
    cout << "\n";
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}