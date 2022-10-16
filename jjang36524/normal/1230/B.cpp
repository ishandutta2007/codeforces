#include <iostream>
using namespace std;
int n, k;
char arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cin >> arr;
	if (n == 1 && k == 1)
	{
		cout << '0';
		return 0;
	}
	int changed = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (changed == k)
			break;
		if (!i != arr[i]-'0')
			changed++;
		cout << !i;
	}
	cout << arr + i;
}