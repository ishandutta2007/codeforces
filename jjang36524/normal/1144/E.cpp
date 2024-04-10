#include <iostream>
#include <string.h>
using namespace std;
char resarr[200100];
char arr1[200100];
char arr2[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cin >> arr1 >> arr2;
	int i;
	for (i = 0; i < N; i++)
	{
		resarr[i] = arr1[i];
		arr1[i] -= 'a';
		arr2[i] -= 'a';
	}
	for (i = N - 1; i >= 0; i--)
	{
		if (arr2[i] < arr1[i])
		{
			int j;
			j = i - 1;
			while (!arr2[j])
			{
				arr2[j] = 25;
				j--;
			}
			arr2[j]--;
			arr2[i] += 26;
		}
		int minusres = arr2[i] - arr1[i];
		if (minusres % 2)
		{
			
			if (resarr[i+1] > 'm')
			{
				resarr[i+1] -= 13;
				resarr[i]++;
			}
			else
			{
				resarr[i + 1] += 13;
			}
		}
		if (resarr[i]+minusres/2 > 'z')
		{
			resarr[i] -= 26;
			resarr[i] += minusres / 2;
			resarr[i - 1]++;
		}
		else
		{
			resarr[i] += minusres / 2;
		}
	}
	cout << resarr;
}