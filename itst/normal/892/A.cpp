#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t , n = 0 , maxA = 0 , maxB = 0;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		int a;
		cin >> a;
		n += a;
	}
	for(int i = 0 ; i < t ; i++)
	{
		int a;
		cin >> a;
		if(a > maxA)
		{
			maxB = maxA;
			maxA = a;
		}
		else		if(a > maxB)	maxB = a;
	}
	printf("%s" , maxA + maxB >= n ? "YES" : "NO");
	return 0;
}