#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[200100];
int plu,minu;
long long ps, ms;
int main()
{
	
	cin >> N;
	int i;
	int isplus = 1;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] < 0)
			isplus = (isplus + 1) % 2;
		if (isplus)
			plu++;
		else
			minu++;
	}
	for (i = 0; i < N; i++)
	{
		ps += plu;
		ms += minu;
		if (arr[i] > 0)
		{
			plu--;
		}
		else
		{
			minu--;
			swap(plu, minu);
		}
	}
	cout << ms << ' ' << ps;
}