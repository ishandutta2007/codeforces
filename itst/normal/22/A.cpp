#include<bits/stdc++.h>
using namespace std;
int num[201];
int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> num[i];
	sort(num , num + n);
	int minN = num[0];
	for(int i = 1 ; i < n && minN == num[0] ; i++)
		if(minN != num[i])
		{
			cout << num[i];
			minN = num[i];
		}
	if(minN == num[0])	cout << "NO";
	return 0;
}