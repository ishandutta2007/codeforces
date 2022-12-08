#include <iostream>

using namespace std;

long long x , y , n;

void work ()
{
	cin >> x >> y;
	cin >> n;
	n = n % 6;
	if ( n == 0 )
	{
		cout << ( ( ( -y + x ) % 1000000007 ) + 1000000007 ) % 1000000007 << endl;
	}
	if ( n == 1 )
	{
		cout << ( ( ( x ) % 1000000007 ) + 1000000007 ) % 1000000007 << endl;
	}
	if ( n == 2 )
	{
		cout << ( ( ( y ) % 1000000007 ) + 1000000007 ) % 1000000007 << endl;
	}
	if ( n == 3 )
	{
		cout << ( ( ( y - x ) % 1000000007 ) + 1000000007 ) % 1000000007 << endl;
	}
	if ( n == 4 )
	{
		cout << ( ( ( -x ) % 1000000007 ) + 1000000007 ) % 1000000007 << endl;
	}
	if ( n == 5 )
	{
		cout << ( ( ( -y ) % 1000000007 ) + 1000000007 ) % 1000000007 << endl;
	}
}

int main ()
{
	work ();
	return 0;
}