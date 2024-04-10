#include<bits/stdc++.h>
using namespace std;
long long num[100000];
int main(){
	long long n , k , min = 1000000000000000000 , minD = -1;
	cin >> n >> k;
	for(int i = 0 ; i < k ; i++)
	{
		scanf("%I64d" , &num[i]);
		if(min > n % num[i])
		{
			min = n % num[i];
			minD = i;
		}
	}
	cout << minD + 1 << " " << n / num[minD];
	return 0;
}