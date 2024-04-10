#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,l=0,a,b,m=0,i=1;
	cin >> n >> a;
	for (; i<n; i++){
		cin >> b;
		if (b<=a){
			if (m<i-l){
				m=i-l;
			}
			l=i;
		}
		a=b;
	}
	if (m<i-l){
		m=i-l;
	}
	cout << m;
	return 0;
}