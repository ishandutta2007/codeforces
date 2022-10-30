#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int ll;

int main(int argc, char** argv)
{
	int n = 0, d[10], a[10] = {0};
	ll num, cur_num;

	cin >> num;

	while(num)
		d[n++] = num % 10, num /= 10;

	for(int i = 0, j = n - 1; i < j; ++i, --j)
		swap(d[i], d[j]);

	int ans = n, cur;
	a[n - 1] = 1;

	for(;;)
	{
		cur = cur_num = 0;

		for(int i = 0; i < n; ++i)
			cur += !a[i], cur_num = a[i] ? 10 * cur_num + d[i] : cur_num;

		if(cur == n)
			break;

		int i;
		for(i = 0; !a[i]; ++i);

		int x = (int)sqrt(cur_num);
		ans = x * x == cur_num && d[i] ? min(ans, cur) : ans;

		for(i = n - 1; i >= 0 && a[i]; --i)
			a[i] = 0;

		if(i >= 0)
			a[i] = 1;
	}

	cout << (ans == n ? -1 : ans) << endl;

	return 0;
}