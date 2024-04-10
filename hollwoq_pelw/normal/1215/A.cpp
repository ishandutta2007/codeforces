#include <bits/stdc++.h>
using namespace std;
int a1,a2,k1,k2,n;
int main(){
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	int low=a1*(k1-1)+a2*(k2-1);
	cout << max(n-low,0) << endl;
	if (k1>k2) swap(k1,k2),swap(a1,a2);
	int T1=min(n/k1,a1); a1-=k1; n-=T1*k1;
	cout << T1+n/k2;
}