#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

inline bool bukva (char t)
{
    return (t >= 'A' && t <= 'Z');
}

inline bool tsifra (char t)
{
    return (t >= '0' && t <= '9');
}

int main ()
{

    int n, i, j;
    cin >> n;
    vector <string> ans;
    for (i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int smena = 0;
        for (j = 1; j < s.size(); j++)
            if (!((bukva(s[j]) && bukva(s[j-1])) || (tsifra(s[j]) && tsifra(s[j-1])))) smena++;
        if (smena != 1)
        {
            int c = 0;
            string r = "";
            j = 1;
            while (tsifra(s[j]))
            {
                r += s[j];
                j++;
            }
            j++;
            while (j < s.size())
            {
                c *= 10;
                c += (s[j] - '0');
                j++;
            }
            string out = "";
            while (c > 0)
            {
                if (c % 26 == 0) {out = "Z" + out; c /= 26; c--;}
                else {out = (char)('A' + (c % 26) - 1) + out; c /= 26;}
            }
            string otv = out + r;
            ans.push_back(otv);
        }
        else
        {
            string c = "";
            string r = "";
            j = 0;
            while (bukva(s[j]))
            {
                c += s[j];
                j++;
            }
            while (j < s.size())
            {
                r += s[j];
                j++;
            }
            string otv = "R" + r + "C";
            int res = 0, prev = 1;
            for (j = c.size() - 1; j >= 0; j--)
            {
                res += (s[j] - 'A' + 1) * prev;
                prev *= 26;
            }
            char buff[30];
            otv += itoa(res, buff, 10);
            ans.push_back(otv);
        }
    }

    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";

}