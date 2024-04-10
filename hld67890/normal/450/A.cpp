#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int n , s;
};

int n , m;
queue < node > q;

void work ()
{
	int i , mi;
	node a;
	cin >> n >> m;
	for ( i = 1 ; i <= n ; i++ )
	{
		cin >> a.s;
		a.n = i;
		q.push ( a );
	}
	while ( q.size () != 0 )
	{
		a = q.front ();
		q.pop ();
		a.s -= m;
		mi = a.n;
		if ( a.s > 0 )
		{
			q.push ( a );
		}
	}
	cout << mi << endl;
}

int main ()
{
	work ();
	return 0;
}