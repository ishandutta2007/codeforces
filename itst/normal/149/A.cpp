#include<bits/stdc++.h>
using namespace std;
int num[12];
int main()
{
	int k , i = 11 , sum = 0;
	cin >> k;
	for(int j = 0 ; j <= i ; j++)	cin >> num[j];
	sort(num , num + i + 1);
	while(i + 1 && sum < k)	sum += num[i--];
	cout << (k <= sum ? 11 - i : -1);
	return 0;
}