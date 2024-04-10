#include <iostream>
#include <string>
#include <map>

using namespace std;
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	long long n,x,y;
	cin >> n >> x >> y;
	if (n>y || (y-n+1)*(y-n+1)+n-1<x) cout << -1;
	else {
		cout << y-n+1 << ' ';
		for (int i=1; i<n; i++) cout << 1 << ' ';
	}
	return 0;
}