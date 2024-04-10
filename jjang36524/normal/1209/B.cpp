#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int a[101];
int b[101];
int sta[101];
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		char c;
		cin >> c;
		sta[i] = c - '0';
	}
	for (i = 0; i < N; i++)
	{
		cin >> a[i] >> b[i];
	}
	int ans = 0;
	for (i = 0; i < 1000; i++)
	{
		int j;
		for (j = 0; j < N; j++)
		{
			if (i >= b[j] && !((i - b[j]) % a[j]))
			{
				sta[j] = (sta[j] + 1) % 2;
			}
		}
		int t=0;
		for (j = 0; j < N; j++)
		{
			if (sta[j])
				t++;
		}
		ans = max(t, ans);
	}
	cout << ans;
}