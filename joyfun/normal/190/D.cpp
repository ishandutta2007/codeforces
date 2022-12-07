#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

long long n, k, num[555555];
long long l = 0, r = 0;
long long ans = 0;
map<int, int> save;

int main() {
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i ++)
	cin >> num[i];
    save[num[0]] ++;
    if (k == 1) {
	cout << n * (n + 1) / 2 << endl;
	return 0;
    }
    while (r != n - 1) {
	r ++;
	save[num[r]] ++;
	if (save[num[r]] >= k) {
	    while (save[num[r]] >= k) {
		save[num[l]] --;
		l ++;
		ans += n - r;
	    }
	}
    }
    cout << ans << endl;
    return 0;
}