#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);

int main()
{
	int n;
	int t[100];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> t[i];
	}
	if(t[0]>=16){
		cout << 15;
		return 0;
	}
	for(int i=0;i<n-1;i++){
		if(t[i+1]-t[i]>15){
			cout << t[i]+15;
			return 0;
		}
	}
	if(t[n-1]<=75){
		cout << t[n-1]+15;
		return 0;
	}
	cout << 90;
	return 0;
}