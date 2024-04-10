#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		map<int, int>x;
		int N;
		cin >> N;
		for(int i=0;i<N;i++)
		{
			int a;
			cin >> a;
			x[a]++;
		}
		cout << N - (*x.begin()).second << '\n';
	}
}