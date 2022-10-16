#include <iostream>
#include <algorithm>
using namespace std;
int N;
int colormin[101];
int inp[101];
int colorcount;
int main()
{
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++)
	{
		cin >> inp[i];
	}
	sort(inp, inp + N);
	for (i = 0; i < N; i++)
	{
		
		int succ=0;
		for (j = 0; j < colorcount; j++)
		{
			if (!(inp[i] % colormin[j]))
			{
				succ = 1;
				break;
			}
				
		}
		if (!succ)
		{
			colormin[colorcount] = inp[i];
			colorcount++;
		}
	}
	cout << colorcount;
}