#include <iostream>
using namespace std;
int N;
int x, y;
char arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> x >> y;
	cin >> arr;
	int i;
	int ans = 0;
	for (i = N - 1; i > N - 1 - y; i--)
	{
		ans += arr[i]-'0';
	}
	ans += '1'-arr[N - 1 - y];
	for (i = N - 2-y; i > N - 1 - x; i--)
	{
		ans += (arr[i]-'0');
	}
	cout << ans;
}