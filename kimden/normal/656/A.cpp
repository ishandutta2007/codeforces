#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long k=1;
	for(int i=0;i<n;i++){
		k*=2;
		if(i==12){
			k-=100;
		}
	}
	cout << k;
	return 0;
}