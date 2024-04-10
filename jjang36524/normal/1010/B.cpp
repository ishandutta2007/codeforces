#include <iostream>
using namespace std;
int N, M;
int seq[30];
int main()
{
	cin >> M>>N;
	int i;
	for (i = 0; i < N; i++)
	{
		cout << 1<< endl;
		fflush(stdout);
		cin >> seq[i];
		if (!seq[i])
			return 0;
	}
	int s = 1, e = M;
	i = 0;
	while (s != e)
	{
		int m = (s + e) / 2;
		cout << m<< endl;
		fflush(stdout);
		int res;
		cin >> res;
		if (!res)
		{
			return 0;
		}

		if (!(res + seq[i]))
		{
			e = m;
		}
		else
		{
			s = m + 1;
		}
		i = (i + 1) % N;
	}
	cout << s << endl;
}