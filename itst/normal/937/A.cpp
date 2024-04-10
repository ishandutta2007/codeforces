#include<bits/stdc++.h>
using namespace std;
int pot[601];
int main(){
	int n , num = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		scanf("%d" , &a);
		pot[a]++;
	}
	for(int i = 1 ; i <= 600 ; i++)
		if(pot[i])	num++;
	cout << num;
	return 0;
}