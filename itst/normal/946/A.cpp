#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n , sum = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		sum += abs(a);
	}
	cout << sum;
	return 0;
}