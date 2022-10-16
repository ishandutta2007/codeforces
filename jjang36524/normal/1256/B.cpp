#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[110];
int revarr[110];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		int i;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i + 1];
		}
		for (i = 0; i < n; i++)
		{
			revarr[arr[i + 1]] = i + 1;
		}
		int maxpos = 1;
		int j = 0;
		for (i = 0; i < n;)
		{
			int diff = revarr[j+1];
			for (i = diff-1; i >=maxpos; i--)
			{
				if (arr[i] < arr[i + 1])
					break;
				swap(arr[i], arr[i + 1]);
			}
			maxpos = max(maxpos, diff);
			i = maxpos;
			j++;
			if (j >= n)
				break;
		}
		for (i = 0; i < n; i++)
		{
			cout << arr[i + 1]<<' ';
		}
		cout << '\n';
	}
}