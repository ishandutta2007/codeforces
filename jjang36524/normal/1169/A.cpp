
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (b == d)
	{
		
		cout << "YES";
		return 0;
	}
		
	while (b != c || d != e)
	{
		int bm=0, dm=0;
		
		if (b != c)
		{
			b++;
			if (b > a)
				b = 1;
			bm = 1;
		}
		if (d != e)
		{
			d--;
			if (!d)
				d = a;
			dm = 1;
		}
		if (b == d && bm && dm)
		{
			cout << "YES";
			return 0;
		}
			
	}
	cout << "NO";
}