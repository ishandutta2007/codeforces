#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a;
	cin >> n>> a;
	int t[101];
	a--;
	int sum=0;
	for(int i=0;i<n;i++){
		cin >> t[i];
		sum+=t[i];
	}
	int l=a-1,r=a+1;
	while(l>=0 && r<=n-1){
		if(t[l]+t[r]==1){
			sum-=(t[l]+t[r]);
		}
		l--;
		r++;
	}
	cout << sum;
}