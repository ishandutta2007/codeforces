#include<iostream>

using namespace std;

long long n, k;
long long fib[86];
int l[100];
int p[55];

int main () {
	cin >> n >> k;
	k--;
	fib[0]=1;
	fib[1]=1;
	for (int i=2; i<86; i++) {
		fib[i]=fib[i-1]+fib[i-2];
	}
	for (long long i=k; i>0;) {
		for (int j=0; j<84; j++) {
			if (i>=fib[j] && i<fib[j+1]) {
				i-=fib[j];
				l[j]=1;
				break;
			}
		}
	}
	if (l[0]) l[1]=1;
	for (int i=1; i<=n; i++) {
		p[i]=i;
	}
	for (int i=n-1; i>0; i--) {
		if (l[i]) swap(p[n-i], p[n-i+1]);
	}
	for (int i=1; i<=n; i++) {
		cout << p[i] << " ";
	}
	return 0;
}