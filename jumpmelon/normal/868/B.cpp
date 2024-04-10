#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZ = 3600 * 12;

int main()
{
	int h, m, s, t1, t2;
	scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);
	h = h * SIZ / 12 + m * SIZ / 12 / 60 + s * SIZ / 12 / 60 / 60;
	m = m * SIZ / 60 + s * SIZ / 60 / 60;
	s = s * SIZ / 60;
	t1 = t1 * SIZ / 12;
	t2 = t2 * SIZ / 12;
	if(t1 > t2)
		swap(t1, t2);
	if(t1 <= h && h <= t2 &&
		t1 <= m && m <= t2 &&
		t1 <= s && s <= t2)
		puts("YES");
	else if((h <= t1 || h >= t2) && 
		(m <= t1 || m >= t2) &&
		(s <= t1 || s >= t2))
		puts("YES");
	else
		puts("NO");
	return 0;
}