#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 1000000007;
const int inf = 1000000000;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    string s, p;
    cin >> s >> p;

    int max_ans = 0;
    int pos_p = 0;

    for (int s_pos = 0; s_pos < (int) s.size(); s_pos++)
    {
        if (s[s_pos] == p[pos_p])
        {
            ++pos_p;
            if (pos_p == (int) p.size())
            {
                pos_p = 0;
                ++max_ans;
            }
        }
    }

    vector <pii> adress((int) s.size());
    for (int i = 0; i < (int) s.size(); i++)
    {
        if (s[i] != p[0]) {adress[i] = mp(-1, 0); continue;}
        pos_p = 1;
        if ((int) p.size() == 1) {adress[i] = mp(i, 0); continue;}
        int s_pos, price = 0;
        for (s_pos = i + 1; s_pos < (int) s.size(); s_pos++)
            if (s[s_pos] == p[pos_p])
        {
            ++pos_p;
            if (pos_p == (int) p.size()) break;
        }
            else ++price;
        if (pos_p == (int) p.size()) adress[i] = mp(s_pos, price);
        else adress[i] = mp(-1, 0);
    }

    //for (int i = 0; i < (int) s.size(); i++)
    //    cout << adress[i].first << " " << adress[i].second << "\n";

    vector <vector <int> > dp((int) s.size(), vector <int> (max_ans + 1, inf));
    for (int i = 0; i < (int) s.size(); i++)
        dp[i][0] = 0;

    if (adress[(int) s.size() - 1].first == (int) s.size() - 1) dp[(int) s.size() - 1][1] = 0;

    for (int i = (int) s.size() - 2; i >= 0; i--)
    {
        for (int k = 1; k <= max_ans; k++)
        {
            if (adress[i].first == -1) dp[i][k] = dp[i + 1][k];
            else
            {
                dp[i][k] = dp[i + 1][k];
                if (adress[i].first + 1 == (int) s.size() && k == 1) dp[i][k] = adress[i].second;
                else if (adress[i].first + 1 < (int) s.size()) dp[i][k] = min(dp[i][k], dp[adress[i].first + 1][k - 1] + adress[i].second);
            }

        }
        //cout << dp[i][1] << " " << dp[i][2] << "\n";
    }

    int pos = -1, out = 0;
    int u = 0;
    for (; u <= max_ans; u++)
        if (dp[0][u]) break;
    --u;
    out = u;
    for (int i = u; i <= max_ans; i++)
    {
        for (int j = pos + 1; j < dp[0][i]; j++)
            cout << out << " ";
        pos = dp[0][i];
        out = i;
        cout << out << " ";
    }

    int rest = (int) s.size() - pos;
    while (rest > max_ans * (int) p.size())
    {
        cout << max_ans << " ";
        --rest;
    }

    for (out = max_ans - 1; out >= 0; out--)
        for (int i = 0; i < (int) p.size(); i++)
        cout << out << " ";

}