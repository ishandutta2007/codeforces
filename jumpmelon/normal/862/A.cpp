#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n, x, ans;
	scanf("%d%d", &n, &x);
	ans = x;
	while(n--)
	{
		int v;
		scanf("%d", &v);
		if(v < x)
			ans--;
		else if(v == x)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}