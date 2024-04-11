#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, a[1000005];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1, a+n+1);
	int p = 1;
	for(int i=1; i<=n; i++){
		if(a[i] >= p) p++;
	}
	cout << p;
}