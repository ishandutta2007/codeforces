#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

int a[2001], b[2002], c[2002], d[2002];
int n;

int hash(int x, int y)
{
    return (b[x + y] - b[x]) * a[n - x - 1];
}

int hash1(int x, int y)
{
    return (c[x + y] - c[x]) * a[n - x - 1];
}

int hash2(int x, int y)
{
    return (d[x + y] - d[x]) * a[n - x - 1];
}

int main()
{
    int n1, n2, i, j;
    char s[2001], s1[2001], s2[2001];
    vector <int> v, w;
    set <pair<int, int> > ans;

    scanf("%s %s %s", s, s1, s2);

    n = strlen(s);
    n1 = strlen(s1);
    n2 = strlen(s2);

    a[0] = 1;

    for (i = 1; i < n; i++) a[i] = a[i - 1] * 31;

    for (i = 0; i < n; i++) b[i + 1] = b[i] + (s[i] - 'a' + 1) * a[i];

    for (i = 0; i < n1; i++) c[i + 1] = c[i] + (s1[i] - 'a' + 1) * a[i];

    for (i = 0; i < n2; i++) d[i + 1] = d[i] + (s2[i] - 'a' + 1) * a[i];

    for (i = 0; i <= n - n1; i++) {
	if (hash(i, n1) == hash1(0, n1)) v.push_back(i);
    }

    for (i = 0; i <= n - n2; i++) {
	if (hash(i, n2) == hash2(0, n2)) w.push_back(i);
    }

    for (i = 0; i < v.size(); i++) {
	for (j = 0; j < w.size(); j++) {
	    if (v[i] <= w[j] && v[i] + n1 <= w[j] + n2) {
		ans.insert(make_pair(w[j] + n2 - v[i], hash(v[i], w[j] + n2 - v[i])));
	    }
	}
    }

    printf("%d\n", (int)ans.size());

    return 0;
}