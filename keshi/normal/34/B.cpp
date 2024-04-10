#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[110],m,s=0;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int i=0;
	while (i<m && a[i]<0){
		s-=a[i];
		i++;
	}
	cout << s;
	return 0;
}