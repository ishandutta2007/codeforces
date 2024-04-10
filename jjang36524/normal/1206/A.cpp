#include <iostream>
#include <set>
using namespace std;
multiset<int>a, b;
int N, M;
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		a.insert(x);
	}
	cin >> M;
	for (i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		b.insert(x);
	}
	multiset<int>::iterator y, z;
	for (y = a.begin(); y != a.end(); y++)
	{
		for (z = b.begin(); z != b.end(); z++)
		{
			if ((!a.count(*y + *z)) && (!b.count(*y + *z)))
			{
				cout << *y << ' ' << *z;
				return 0;
			}
		}
	}
}