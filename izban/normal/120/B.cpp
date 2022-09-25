#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;
int a[100001];
int main() {
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
	int n,k,r,l;
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	int i=k-1;
	while (a[i]==0) {
		i++;
		if (i==n) i=0;
	}
	cout << i+1;
	return 0;
}