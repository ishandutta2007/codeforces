#include<bits/stdc++.h>
using namespace std;
int num[1050];
int main(){
	int n , numM = 0;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &num[i]);
	for(int i = 2 ; i < n ; i++)
		if(num[i] > num[i - 1] && num[i] > num[i + 1] || num[i] < num[i - 1] && num[i] < num[i + 1])
			numM++;
	cout << numM;
	return 0;
}