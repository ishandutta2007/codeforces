#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

char s[505];
int n;

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int curx = 0;
        int cury = 0;
        for (int j = i; j < n; j++)
        {
            if (s[j] == 'U') cury++;
            if (s[j] == 'D') cury--;
            if (s[j] == 'R') curx++;
            if (s[j] == 'L') curx--;
            if (curx == 0 && cury == 0) answer++;
        }
    }
    cout << answer << endl;
    return 0;
}