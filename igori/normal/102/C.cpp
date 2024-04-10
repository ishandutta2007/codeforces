#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long k;
string s;
long long cnt[1020];
pair<int, char> d[1020];
int use[1020];

int main()
{
    fill(use, use + 600, 100);
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'a']++;
    }
    int cucu = 0;
    for (int i = 0; i < 26; i++)
        d[i] = {cnt[i], i + 'a'};
    sort(d, d + 26);
    for (int i = 0; i < 26; i++)
    {
        if (k - d[i].first >= 0)
        {
            k -= d[i].first;
            use[d[i].second] = 0;
            //cout << d[i].second << endl;
        }
        else
        {
            if (d[i].first != 0)
            {
                cucu++;
            }
        }
    }
    cout << cucu << "\n";
    int calc = 0;
    for (int i = 0; i < s.size(); i++)
    {
        //cout << s[i] << " " << use[s[i]] << endl;
        if (use[s[i]])
            cout << s[i];
    }
}