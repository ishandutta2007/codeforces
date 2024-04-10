#include <iostream>
#define int long long
using namespace std;
int arr[] = { 0,2,3,1 };
int recur(int n,int s)
{
	if (s == 1)
		return 0;
	int div = s/4;
	return recur(n % div, div) + div * arr[n / div];
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int num;
		cin >> num;
		int bp = (num+2) / 3;
		int s = 0, i = 1;
		while (s < bp)
		{
			s += i;
			i *= 4;
		}
		i /= 4;
		s -= i;
		s++;
		int startnum = (s-1) * 3 + 1;
		int first = startnum + (bp - s);
		int second = i * 2 + recur(bp - s, i);
		int third = first ^ second;
		if (num % 3 == 1)
			cout << first << '\n';
		else if (num % 3 == 2)
			cout << second << '\n';
		else
			cout << third << '\n';
	}
}