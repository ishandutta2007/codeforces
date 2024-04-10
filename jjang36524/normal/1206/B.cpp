#include <iostream>
using namespace std;
long long inp[100100];
int N;
int pcou;
int is0;
long long ans;
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> inp[i];
		if (inp[i] > 0)
		{
			
			ans += inp[i] - 1;
		}
		else if (!inp[i])
		{
			is0 = 1;
			ans++;
		}
		else
		{
			ans += -1 - inp[i];
			pcou++;
		}
	}
	if (!is0&&pcou%2)
		ans += 2;
	cout << ans;
}