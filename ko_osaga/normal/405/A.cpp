#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main(){
	int n, a[105];
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	for(int i=0; i<n; i++) printf("%d ",a[i]);
}