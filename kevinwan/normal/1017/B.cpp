#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;
int main() {
	int n,i;
	scanf("%d", &n);
	cin >> a >> b;
	ll zz=0, zo=0,oz=0,oo=0;
	for (i = 0; i < n; i++) {
		a[i] -= '0', b[i] -= '0';
		a[i] = 1 - a[i], b[i] = 1 - b[i];
		if (a[i] == 0 && b[i] == 0)zz++;
		else if (a[i] == 0 && b[i] == 1)zo++;
		else if (a[i] == 1 && b[i] == 0)oz++;
		else if (a[i] == 1 && b[i] == 1)oo++;
	}
	printf("%lld", zo*oo + zo * oz + zz * oo);
	getchar(); getchar();
}