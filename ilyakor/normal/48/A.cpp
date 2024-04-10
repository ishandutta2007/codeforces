#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

bool wins(string s, string t)
{
    if (s == "rock") return t == "scissors";
    if (s == "scissors") return t == "paper";
    return t == "rock";
}

int main()
{
    string rd = "FMS";
    vector<string> v(3);
    for (int i = 0; i < 3; ++i)
        cin >> v[i];
    for (int i = 0; i < 3; ++i)
    {
        bool ok = true;
        for (int j = 0; j < 3; ++j)
            if (i != j)
            {
                if (!wins(v[i], v[j]))
                {
                    ok = false;
                    break;
                }
            }
        if (ok)
        {
            cout << rd[i] << "\n";
            return 0;
        }
    }
    cout << "?\n";
    return 0;
}