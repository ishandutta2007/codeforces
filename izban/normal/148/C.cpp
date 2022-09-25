#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int n,a,b,sum;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> a >> b;
	if (n-a==1 && n>1) {
		cout << -1;
		return 0;
	}
	cout << 1+(b==0) << ' ';
	sum+=1;
	for (int i=1; i<n; i++) {
		if (i<=b) {
			cout << sum+1 << ' ';
			if (i<b) sum=sum*2+1; else sum++;
		} else if (i<=a+b+(b==0)) {
			cout << sum+i-b << ' ';
		} else cout << "1 ";
	}
	return 0;
}