#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
	cin >> N >> M;
	int n;
	cin >> n;
	int mini = 0;
	int maxi = 0;
	mini = max(0, n - N);
	maxi = min(n, M);
	cout << maxi - mini+1;
}