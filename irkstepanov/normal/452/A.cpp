#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int main()
{

    string m[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < 8; i++)
        if (s.size() == m[i].size())
    {
        bool ok = true;
        for (int j = 0; j < s.size(); j++)
            if (!(s[j] == '.' || s[j] == m[i][j])) ok = false;
        if (ok) cout << m[i];
    }

    cout << "\n";

}