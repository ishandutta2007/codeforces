#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std;
int N;
int arr[200100];
int main()
{
	int i;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << min(a - 1, abs(d - c) + b)<<'\n';
	}
}