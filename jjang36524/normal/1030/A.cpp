#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (a)
		{
			cout << "HARD";
			return 0;
		}
			
	}
	cout << "EASY";
}