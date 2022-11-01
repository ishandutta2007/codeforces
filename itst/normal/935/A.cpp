#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , num = 1;
	cin >> n;
	for(int i = 2 ; i * i <= n ; i++)
		if(n % i == 0)
			if(n / i == i)
				num++;
			else
				num += 2;
	cout << num;
	return 0;
}