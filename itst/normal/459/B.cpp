#include<bits/stdc++.h>
using namespace std;
int num[200001];
int main()
{
	long long n , fir = 1 , end;
	cin >> n;
	for(int i = 0 ; i < n ; i++)	cin >> num[i];
	sort(num , num + n);
	end = n - 2;
	cout << num[n - 1] - num[0] << " ";
	if(num[n - 1] == num[0])
	{
		cout << n * (n - 1) / 2;
		return 0;
	}
	while(num[fir] == num[0] && fir < n)	fir++;
	while(num[end] == num[n - 1] && end + 1)	end--;
	cout << fir * (n - 1 - end);
	return 0;
}