#include <bits/stdc++.h>
using namespace std;

int arr[4][105];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		arr[0][i] = i*2;
		arr[3][i] = i*2+1;
		arr[1][i] = n*2+i*2;
		arr[2][i] = n*2+i*2+1;
	}
	for (int i = 0;i < n;i++)
	{
		if (arr[1][i] < m) printf("%d ", arr[1][i]+1);
		if (arr[0][i] < m) printf("%d ", arr[0][i]+1);
		if (arr[2][i] < m) printf("%d ", arr[2][i]+1);
		if (arr[3][i] < m) printf("%d ", arr[3][i]+1);
	}
	return 0;
}