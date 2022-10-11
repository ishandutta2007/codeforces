#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a,c[1010]={0};
	cin >> n;
	for (int i=0 ;i<n;i++){
		cin >> a;
		c[a]++;
	}
	int m=0,r=0;
	for (int i=0; i<1010; i++){
		if (c[i]>0){
			r++;
			m=max(m,c[i]);
		}
	}
	cout << m << ' ' << r;
	return 0;
}