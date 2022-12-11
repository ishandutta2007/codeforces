#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;

string binary (ll x)
{
    string ans = "";
    if (!x) return "0";
    while (x)
    {
        ans += (char) (x % 2 + '0');
        x /= 2;
    }
    string otv = "";
    for (int i = (int) ans.size() - 1; i >= 0; i--)
        otv += ans[i];
    return otv;
}

ll decimal (string x)
{
    ll ans = 0;
    ll p = 1;
    for (int i = (int) x.size() - 1; i >= 0; i--)
    {
        ans += (x[i] - '0') * p;
        p *= 2;
    }
    return ans;
}

bool better (string a, string b)
{
    int ka = 0, kb = 0;
    for (int i = 0; i < a.size(); i++)
        ka += (a[i] == '1');
    for (int i = 0; i < b.size(); i++)
        kb += (b[i] == '1');
    return (ka > kb);
}

bool only1 (string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0') return false;
    return true;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    while (n--)
    {
        ll l, r;
        cin >> l >> r;
        string a = binary(l), b = binary(r);
        if (b.size() > a.size())
        {
            if (only1(b)) {cout << r << "\n"; continue;}
            string s = "";
            for (int i = 0; i < (int) b.size() - 1; i++)
                s += "1";
            cout << decimal(s) << "\n";
        }
        else
        {
            string ans = "";
            if (l == r) {cout << l << "\n"; continue;}
            int i = 0;
            for (; a[i] == b[i]; i++)
                ans += a[i];
            string s1 = ans, s2 = ans;
            s1 += "0";
            while (s1.size() < a.size())
                s1 += "1";
            s2 += "1";
            for (++i; i < b.size() && b[i] == '0'; i++)
                s2 += "0";
            if (i == (int) b.size() - 1) s2 += "1";
            else if (i <= (int) b.size() - 2)
            {
                bool ok = true;
                for (; i < b.size(); i++)
                    if (b[i] == '0') ok = false;
                if (ok) while (s2.size() < b.size()) s2 += "1";
                else
                {
                    s2 += "0";
                    while (s2.size() < b.size()) s2 += "1";
                }
            }
            //cout << s1 << " " << s2 << "\n";
            if (better(s2, s1)) cout << decimal(s2) << "\n";
            else cout << decimal(s1) << "\n";
        }
    }

}