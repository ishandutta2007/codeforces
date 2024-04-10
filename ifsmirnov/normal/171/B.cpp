#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long i64;

i64 tr(i64 x)
{
	return x*(x+1)/2;
}

int main()
{	

	i64 n;
	cin >> n;
	cout << tr(n*2+n-2) + 3*tr(n-1) << endl;
	
	return 0;
}