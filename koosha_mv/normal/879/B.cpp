#include <iostream>
 
using namespace std;
 
int main()
{
    long long n, k, a, p, c = 0;
    cin >> n >> k >> p;
    for(int i = 1; i < n && c < k; ++i)
		cin >> a, c = (p > a ? c + 1 : 1), p = max(a, p);
	cout << p;
    return 0;
}