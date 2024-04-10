#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int n, r;
		cin >> n >> r;
		int i;
		int an = 0;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
			
		}
		sort(arr, arr + n);
		int counts = 0;
		for(i=n-1;i>=0;i--)
		{
			if ((i+1==n) || arr[i] != arr[i + 1])
			{
				an = max(an, min(counts+1, (arr[i] + r - 1) / r));
				counts++;
			}
			
		}
		cout << an << '\n';
	}
}