#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		if (i % 2)
			cout << "I love ";
		else
			cout << "I hate ";
		if (i == N - 1)
			cout << "it ";
		else
			cout << "that ";
	}
}