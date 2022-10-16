#include <iostream>
#include <string>
using namespace std;
int N;
int main()
{
	cin >> N;
	int i;
	int a = 0;
	for (i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s[0] == 'T')
			a += 4;
		if (s[0] == 'C')
			a += 6;
		if (s[0] == 'O')
			a += 8;
		if (s[0] == 'D')
			a += 12;
		if (s[0] == 'I')
			a += 20;
	}
	cout << a;
}