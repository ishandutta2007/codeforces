#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int kol = 0;
    int ans = 0;

    string s;
    while (getline(cin, s))
    {
        if (s[0] == '+')
        {
            ++kol;
            continue;
        }
        if (s[0] == '-')
        {
            --kol;
            continue;
        }
        string name = "", text = "";
        int i;
        for (i = 0; ; i++)
        {
            if (s[i] != ':') name += s[i];
            else break;
        }
        for (++i; i < s.size(); i++)
            text += s[i];
        ans += text.size() * kol;
    }

    cout << ans;

}