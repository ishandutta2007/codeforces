#include <algorithm>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int revc[10] = { 0,1,5,1000,1000,2, 1000,1000,8,1000 };
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, d;
		scanf("%d %d %d:%d", &a, &b, &c, &d);
		while (1)
		{
			int minu = revc[(c / 10)] + revc[(c % 10)] * 10;
			int houu = revc[(d / 10)] + revc[(d % 10)] * 10;
			if (houu < a && minu < b)
			{
				printf("%02d:%02d\n", c, d);
				break;
			}
			d++;
			if (d == b)
			{
				d = 0;
				c++;
			}
			if (c == a)
			{
				c = 0;
			}
			
		}
	}
}