#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 100005;

char s[maxn];
int n;
int st[maxn];

int main()
{
    scanf("%s", s);
    n = strlen(s);
    int kv = 0;
    for (int i = 0; i < n; i++)
    {
        if (kv != 0 && st[kv - 1] == s[i]) kv--;
        else st[kv++] = s[i];
    }
    cout << (kv == 0 ? "Yes" : "No") << endl;
	return 0;
}