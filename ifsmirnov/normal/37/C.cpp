#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

int n;
vector<pair<int, int> > len;
vector<pair<int, string> > ans;
int level = 1;
unsigned L = 2;

void getword (unsigned l, int level, string &s)
{
    l--;
   string end = "";
   unsigned etal = -1;
   etal -= l;
   for (int i = 0; i < 32; i++)
   {
       end = (char)('0' + (etal & 1)) + end;
       etal = etal >> 1;
   }
   if (level <= 32)
   {
       s = end.substr(32 - level, level);
   }
   else
   {
       s = string(level - 32, '1') + end;
   }
};

int main()
{
    //freopen("input.txt", "r", stdin);
    string t;
    cin >> n;
    len.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> len[i].first;
        len[i].second = i;
    }
    sort(len.begin(), len.end());
    for (int i = 0; i < len.size();)
    {
        while (level != len[i].fi)
        {
            level++;
            if (L & (1 << 31))
                L = -1;
            else
                L = L << 1;
        }
        while (i < len.size() && len[i].fi == level)
        {
            string foo;
            getword(L, level, foo);
            ans.pb(mp(len[i].second, foo));
            //ans.pb(string(len[i], '0'));
            if (L == 0)
            {
                cout << "NO";
                return 0;
            }
            L--;
            i++;
        }
    }
    
    cout << "YES" << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].second << endl;
    return 0;
}