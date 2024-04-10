#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, T;
int arr[500100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		if (N % 2)
		{
			cout << 7;
			N -= 3;
		}
			
		for (i = 0; i < N / 2; i++)
		{
			cout << 1;
		}
		cout << '\n';
	}
}