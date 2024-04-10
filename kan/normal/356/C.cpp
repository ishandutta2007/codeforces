#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

int kv[5];
int n;

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		kv[a]++;
		sum += a;
	}
	int answer = 5 * n;
	for (int n4 = 0; n4 <= n; n4++)
	{
		int ost = sum - 4 * n4;
		if (ost < 0 || ost % 3 != 0) continue;
		int curans;
		if (n4 >= kv[4])
		{
			curans = n4 - kv[4];
			int kvost = max(0, kv[1] + 2 * kv[2] - (n4 - kv[4]));
			assert(kvost % 3 == 0);
			int kv3need = kvost / 3;
			if (kv[2] >= kv3need) curans += kvost - 2 * kv3need;
			else curans += kvost - 2 * kv[2] - (kv3need - kv[2]);
		} else
		{
			curans = 0;
			int kvost = kv[1] + 2 * kv[2] + (kv[4] - n4);
			assert(kvost % 3 == 0);
			int kv3need = kvost / 3;
			if (kv[2] >= kv3need) curans += kvost - 2 * kv3need;
			else curans += kvost - 2 * kv[2] - (kv3need - kv[2]);
		}
//		cout << n4 << ' ' << curans << endl;
		answer = min(answer, curans);
	}
	if (answer == 5 * n) answer = -1;
	cout << answer << endl;
	return 0;
}