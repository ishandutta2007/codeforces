#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
		
		int a, b;
		cin >> a >> b;
		if (a == b)
			cout << "YES" << '\n';
		else if (a == 1)
			cout << "NO" << '\n';
		else if (a <= 3 && b > 3)
			cout << "NO" << '\n';
		else if (a <= 3)
			cout << "YES" << '\n';
		else
			cout << "YES" << '\n';
	}
}