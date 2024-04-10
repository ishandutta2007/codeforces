#include <bits/stdc++.h>

using namespace std;

namespace program
{
	void work()
	{
		int v1, v2, v3, vm;
		scanf("%d%d%d%d", &v1, &v2, &v3, &vm);
		// max(v1, (vm << 1) + 1) <= a1 <= (v1 << 1)
		// max(v2, (vm << 1) + 1) <= a2 <= (v2 << 1)
		// max(v3, vm) <= a3 <= min(v3 << 1, vm << 1)
		if(max(v1, (vm << 1) + 1) <= (v1 << 1) &&
			max(v2, (vm << 1) + 1) <= (v2 << 1) &&
			max(v3, vm) <= min(v3 << 1, vm << 1))
			printf("%d %d %d\n", v1 << 1, v2 << 1, min(v3 << 1, vm << 1));
		else
			puts("-1");
	}
}

int main()
{
	program::work();
	return 0;
}