#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	stack<int>count;
	long long mul = 1;
	long long ans = 0;
	int lastpos = 0;
	bool over = false;
	for (i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			if (over == true && lastpos <= count.size())
			{
				cout << "OVERFLOW!!!";
				return 0;
			}
			ans += mul;
			if (ans >= (1LL << 32))
			{
				cout << "OVERFLOW!!!";
				return 0;
			}
		}
		if (s == "for")
		{
			int a;
			cin >> a;
			if(!over)
				mul *= a;
			count.push(a);
			if (!over&&mul >= (1LL << 32))
			{
				lastpos = count.size();
				over = true;
			}
		}
		if (s == "end")
		{
			int t = count.top();
			count.pop();
			if (lastpos > count.size())
			{
				over = false;
			}
			if (!over)
				mul /= t;
		}
	}
	cout << ans;
}