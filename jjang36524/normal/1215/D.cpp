#include <iostream>
#include <algorithm>
using namespace std;
int N;
char arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> arr;
	int firstsum=0, secondsum=0;
	bool firstq=false, secondq=false;
	int i;
	for (i = 0; i < N/2; i++)
	{
		if (arr[i] != '?')
			firstsum += arr[i] - '0';
		else
		{
			if (firstq)
			{
				firstq = false;
				firstsum += 9;
			}
			else
				firstq = true;
		}
		if (arr[i+N/2] != '?')
			secondsum += arr[i+N/2] - '0';
		else
		{
			if (secondq)
			{
				secondq = false;
				secondsum += 9;
			}
			else
				secondq = true;
		}
	}
	if (firstsum == secondsum)
	{
		cout << "Bicarp";
	}
	else
	{
		cout << "Monocarp";
	}
}