#include <iostream>
#include <algorithm>
using namespace std;
int maxlen, nowlen;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	nowlen = 1;
	maxlen = 1;
	int a;
	cin >> a;
	int lastcon = a;
	for (i = 1; i < N; i++)
	{
		cin >> a;;
		if (lastcon * 2 < a)
			nowlen = 1;
		else
			nowlen++;
		lastcon = a;
		maxlen = max(nowlen, maxlen);
	}
	cout << maxlen;
}