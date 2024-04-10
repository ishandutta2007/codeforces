#include<bits/stdc++.h>
using namespace std;
int num[51];
int main(){
	int n , k;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)	cin >> num[i];
	if(num[k])	while(num[k + 1] == num[k])	k++;
	else	while(!num[k] && k)	k--;
	cout << k;
	return 0;
}