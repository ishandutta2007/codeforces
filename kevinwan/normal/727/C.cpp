#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5 + 5;
int k[MN];
#define PI 3.14159265358979
int a[1000000];
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		cout <<"? "<< 1 << ' ' << i << endl;
		cin >> a[i];
	}
	cout << "? " << 2 << ' ' << 3 << endl;
	int x;
	cin >> x;
	a[1] = (a[2] + a[3] - x)/2;
	for (i = 2; i <= n; i++)a[i] -= a[1];
	printf("! ");
	for (i = 1; i <= n; i++)printf("%d ", a[i]);
	cout << endl;
}