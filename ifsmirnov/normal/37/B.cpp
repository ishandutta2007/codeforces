#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define fi first
#define se second

vector<pair<pair<int, int>, int > > svit;
int reg, hp, n, maxhp;

int bestsvit ()
{
    for (int i = 0; i < svit.size(); i++)
    {
        if (hp <= (maxhp * svit[i].fi.se) / 100 && svit[i].fi.fi > 0)
        {
            return i;
        }
    }
    return -1;
};

void printno()
{
    cout << "NO";
};
void printans (int sec)
{
    vector<pair<int, int> > ans;
    for (int i = 0; i < svit.size(); i++)
    {
        if (svit[i].fi.fi <= 0)
        {
            ans.push_back(make_pair(-svit[i].fi.fi, svit[i].se));
        }
    }  
    sort(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << sec << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
};
        



int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> maxhp >> reg;
    hp = maxhp;
    svit.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> svit[i].fi.se >> svit[i].fi.fi;
        svit[i].se = i + 1;
    }
    sort(svit.rbegin(), svit.rend());
    
    for (int cmove = 0;; cmove++)
    {
        hp = min(hp + reg, maxhp);
        if (hp <= 0)
        {
            printans(cmove);
            return 0;
        }
        else
        {
            int cursvit = bestsvit();
            if (cursvit == -1)
            {
                if (reg >= 0)
                {
                    printno();
                    return 0;
                }
            }
            else
            {
                reg -= svit[cursvit].fi.fi;
                svit[cursvit].fi.first = -cmove;
            }
        }
    }
    return 0;
};