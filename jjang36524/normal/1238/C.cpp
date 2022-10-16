#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >>N;
	while (N--)
	{
		int n, h;
		cin >> h >> n;
		int i;
		for (i = 0; i < n; i++)
			cin >> arr[i];
		i = 0;
		arr[n] = 0;
		int ans = 0;
		for (;i < n-1; i++)
		{
			
			if(arr[i]-arr[i+1]!=1)
			{
				arr[i] = arr[i + 1] + 1;
			}
				if (arr[i + 1] - arr[i + 2] == 1)
					i++;
				else
				{
					ans++;
					arr[i + 1] = arr[i + 2] + 1;
				}
		}
		cout << ans << '\n';
	}
}