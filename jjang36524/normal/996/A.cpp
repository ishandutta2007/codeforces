#include <iostream>
#include <string>
using namespace std;
int N;
int c[] = { 100,20,10,5,1 };
int main()
{
	cin >> N;
	int i;
	int a = 0;
	for (i = 0; i < 5; i++)
	{
		a += N / c[i];
		N %= c[i];
	}
	cout << a;
}