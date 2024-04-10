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

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int main()
{
    string s;
    cin >> s;
    set<ii> S;
    int x = 0, y = 0;
    S.insert(ii(x, y));
    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] =='R') x++;
        else if (s[i] == 'L') x--;
        else if (s[i] == 'U') y++;
        else if (s[i] == 'D') y--;
        else assert(false);
        bool ok = true;
        if (S.count(ii(x, y))) ok = false;
        int cnt = 0;
        for (int dir = 0; dir < 4; dir++)
        {
            if (S.count(ii(x + dx[dir], y + dy[dir])))
                cnt++;
        }
        if (cnt > 1) ok = false;
        if (!ok)
        {
            printf("BUG\n");
            return 0;
        }
        S.insert(ii(x, y));
    }
    printf("OK\n");
    return 0;
}