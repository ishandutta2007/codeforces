#include <iostream>
using namespace std;
int N,M;
char arr[200100];
int main()
{
	cin >> N;
	cin >> arr;
	int i;
	int ans=0;
	for (i = 2; i <= N; i+=2)
	{
		if (arr[i - 2] == arr[i - 1])
		{
			ans++;
			if (arr[i - 2] == 'b')
				arr[i - 2] = 'a';
			else
				arr[i - 2] = 'b';
		}
	}
	printf("%d\n%s", ans, arr);
}