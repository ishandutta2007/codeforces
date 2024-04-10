#include <iostream>
#include <algorithm>
using namespace std;
int N;
char arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> arr;
	int i;
	int used = 0;
	for (i = 0; i < N; i++)
	{
		if (!(used % 2) && (arr[i] == arr[i + 1]))
		{
			arr[i] = 0;
		}
		else
			used++;
	}
	cout << N-used/2*2 << '\n';
	int u = 0;
	for (i = 0; i < N; i++)
	{
		if (arr[i])
		{
			if ((used) % 2 && (u + 1 == (used)))
				break;
			u++;
			cout << arr[i];
		}
			
	}
}