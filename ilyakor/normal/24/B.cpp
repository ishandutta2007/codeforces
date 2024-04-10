#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int score[100000] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

map<string, vi> M1, M2;

int main()
{
    int nc;
    cin >> nc;
    for (int it = 0; it < nc; it++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (!M1.count(s))
            {
                M1[s] = vi(110, 0);
                M2[s] = vi(110, 0);
            }
            vi& v1 = M1[s];
            vi& v2 = M2[s];
            v1[0] += score[i];
            v2[1] += score[i];
            if (i == 0)
                v1[1]++, v2[0]++;
            else
                v1[i + 1]++, v2[i + 1]++;
        }
    }
    string r1 = "", r2="";
    vi vr1(110, -1), vr2(110, -1);
    for (map<string, vi>::iterator it = M1.begin(); it != M1.end(); it++)
    {
        if (it->second > vr1)
            vr1 = it->second, r1 = it->first;
    }
    for (map<string, vi>::iterator it = M2.begin(); it != M2.end(); it++)
    {
        if (it->second > vr2)
            vr2 = it->second, r2 = it->first;
    }
    cout << r1 << "\n" << r2 << "\n";
    return 0;
}