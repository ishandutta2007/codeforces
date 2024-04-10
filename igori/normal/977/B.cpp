#include <iostream>
#include <string>

using namespace std;

string s;
int n;

#define sz size()
typedef long long ll;
ll cnt(string m, string s)
{
    ll ans = 0;
    for (int i = 0; i + m.sz - 1 < s.sz; i++)
    {
        ll t = 1;
        for (int j = 0; j < m.sz; j++)
        {
            if (m[j] != s[i + j])
                t = 0;
        }
        ans += t;
    }
    return ans;
}

int main()
{
    cin >> n >> s;
    string sss;
    ll maxi = 0;
    for (int i = 0; i < n - 1; i++)
    {
        string ss = "";
        ss = ss + s[i] + s[i + 1];
        if (cnt(ss, s) > maxi)
        {
            maxi = cnt(ss, s);
            sss = ss;
        }
    }
    cout << sss;
}