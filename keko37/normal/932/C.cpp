#include<iostream>

using namespace std;

const int MAXN = 1000005;

int n, a, b;
int l[MAXN];

void idi (int x, int y) {
	l[x]=y;
	for (int i=x+1; i<=y; i++) {
		l[i]=i-1;
	}
}

int main () {
	cin >> n >> a >> b;
	for (int i=1; i<=n; i++) {
		l[i]=i;
	}
	for (int i=0; i<=n; i+=a) {
		if ((n-i)%b==0) {
			int cnt=0;
			int lim=i/a;
			for (int j=0; j<lim; j++) {
				idi(cnt+1, cnt+a);
				cnt+=a;
			}
			lim=(n-i)/b;
			for (int j=0; j<lim; j++) {
				idi(cnt+1, cnt+b);
				cnt+=b;
			}
			for (int j=1; j<=n; j++) {
				cout << l[j] << " ";
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}