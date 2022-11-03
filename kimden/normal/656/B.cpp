#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,i,j;
	int ans=0;
	double rans;
	int m[17],r[17];
	cin >> n;
	for(i=0;i<n;i++){
		cin >> m[i];
	}
	for(i=0;i<n;i++){
		cin >> r[i];
	}
	for(i=0;i<720720;i++){
		for(j=0;j<n;j++){
			if(m[j]!=0 && (i-r[j])%m[j]==0)
				break;
		}
		if(j<n)
			ans++;
	}
	rans = ((double)ans)/720720;
	cout << rans;
	return 0;
}