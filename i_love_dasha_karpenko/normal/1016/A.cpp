#include <iostream>
#include <stdio.h>

using namespace std;
long long n, m, arr[10000007],res=0,cnt=0,a;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++) {
		a = arr[i];
		if (res != 0 && res<=a) { 
			a -= res;
			cnt++;
		}
		else if (res != 0 && res > a) {
			res -= a;
			cout << 0 << ' ';
			continue;
		}
		if (a != 0) {
			cnt += a / m + 1;
			a -= (a / m + 1)*m;
		}
		if (a == 0)res = 0;
		else {
			res = abs(a); cnt--;
		}
		cout << cnt <<' ';
		cnt = 0;
	}
	
}