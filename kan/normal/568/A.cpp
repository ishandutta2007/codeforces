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

const int MAX = 3e6;

bool bad[MAX];
int p, q;
char s[10];

inline bool ispal(int x)
{
    sprintf(s, "%d", x);
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) if (s[i] != s[len - i - 1]) return false;
    return true;
}

int main()
{
    bad[1] = true;
    for (int i = 2; i < MAX; i++) if (!bad[i])
    {
        for (ll j = (ll)i * i; j < MAX; j += i) bad[j] = true;
    }
    scanf("%d%d", &p, &q);
    int kprime = 0;
    int kpal = 0;
    int answer = -1;
    for (int i = 1; i < MAX; i++)
    {
        if (!bad[i]) kprime++;
        if (ispal(i)) kpal++;
        if ((ll)q * kprime <= (ll)p * kpal) answer = i;
    }
    cout << answer << endl;
	return 0;
}