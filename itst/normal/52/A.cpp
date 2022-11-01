#include<bits/stdc++.h>
using namespace std;
int pot[4];
int main(){
	int a;
	scanf("%d" , &a);
	for(int i = 0 ; i < a ; i++)
	{
		int b;
		scanf("%d" , &b);
		pot[b]++;
	}
	cout << a - max(pot[1] , max(pot[2] , pot[3]));
	return 0;
}