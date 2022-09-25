#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;
double c[9];
int ans;
	int n,k;
int a[1000],b[1000];
void s1(int x,int y) {
	swap(a[x],a[y]);
	swap(b[x],b[y]);
}
void heapify(int x) {
	int m=x;
	if (x*2<=n && a[x*2]>a[x]) m=x*2;
	if (x*2+1<=n && a[x*2+1]>a[m]) m=x*2+1;
	if (m!=x) {
		s1(x,m);
		heapify(m);
	}
}
int main() {
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
	cin >> n >> k;
	ans=0;
	for (int i=1; i<=n; i++)  cin >> a[i];
	for (int i=n/2; i>0; i--) heapify(i);
	while (a[1]>0) {
		if (b[1]<3 && a[1]>=k) {
			b[1]++;
			a[1]-=k;
			heapify(1);
		}
		else {
			ans+=a[1];
			a[1]=0;
			heapify(1);
		}
	}
	cout << ans;
	return 0;
}