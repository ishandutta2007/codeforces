#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define pb push_back

const int maxn = 1004;

int a[maxn];
bool used[maxn];
vector<int> answer;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int cur = 1;
		for (int j = 1; j < i; j++) if (i % j == 0 && used[j]) cur = cur / __gcd(cur, j) * j;
		if (cur != i)
		{
			used[i] = true;
			answer.pb(i);
		}
	}
	printf("%d\n", answer.size());
	for (auto x : answer) printf("%d ", x);
	printf("\n");
	return 0;
}