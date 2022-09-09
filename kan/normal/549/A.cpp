#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 55;

int n, m;
char p[maxn][maxn];

inline int check(char a, char b, char c, char d)
{
    string s(4, ' ');
    s[0] = a;
    s[1] = b;
    s[2] = c;
    s[3] = d;
    sort(all(s));
//     cout << s << endl;
    return s == "acef";
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", p[i]);
    }
    int answer = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            answer += check(p[i][j], p[i][j + 1], p[i + 1][j], p[i + 1][j + 1]);
        }
    }
    cout << answer << endl;
	return 0;
}