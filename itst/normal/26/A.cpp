#include<bits/stdc++.h>
using namespace std;
int vis[3001] = {0 , 0 , 1 , 1 , 1 , 1};
int main(){
	int n , num = 0;
	cin >> n;
	for(int i = 6 ; i <= n ; i++)
	{
		int n = 0 , i1 = i;
		for(int j = 2 ; j * j < i1 ; j++)
			if(i1 % j == 0)
			{
				while(i1 % j == 0)	i1 /= j;
				n++;
			}
		if(i1 != 1)	n++;
		if(n == 2)	num++;
	}
	cout << num;
	return 0;
}