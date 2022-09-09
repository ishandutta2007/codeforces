#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 1e5+5;

int sum[maxn];
string s;
int answer, ansl, ansr;
int n;
int sts;
int st[maxn];
bool was;

inline void check(int l, int r)
{
//     cerr << "check " << ' ' << l << ' ' << r << endl;
    if (l >= r) return;
    r++;
    if (sum[r] - sum[l] > answer || (!was))
    {
        answer = sum[r] - sum[l];
        ansl = l;
        ansr = r;
        was = true;
    }
}

inline bool match(char a, char b)
{
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int main()
{
    cin >> s;
    n = s.length();
    memset(sum, 0, sizeof(sum));
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1];
        if (s[i - 1] == '[') sum[i]++;
    }
    answer = 0;
    ansl = 0;
    ansr = 0;
    sts = 0;
    was = false;
    int begin = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[')
        {
//             cerr << "open " << endl;
            if (sts == 0) check(begin, i - 1);
            else check(st[sts - 1] + 1, i - 1);
            st[sts] = i;
            sts++;
        } else if (sts == 0)
        {
//             cerr << "empty" << endl;
            check(begin, i - 1);
            begin = i + 1;
        } else if (match(s[st[sts - 1]],s[i]))
        {
//             cerr << "match" << endl;
            check(st[sts - 1], i);
            sts--;
        } else
        {
//             cerr << "n match " << s[st[sts - 1]] << ' ' << s[i] << endl;
            check(st[sts - 1] + 1, i - 1);
            sts = 0;
            begin = i + 1;
        }
    }
    if (sts != 0) check(st[sts - 1] + 1, n - 1);
    else check(begin, n - 1);
    cout << answer << endl;
    for (int i = ansl; i < ansr; i++) cout << s[i];
    cout << endl;
	return 0;
}