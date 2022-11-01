#include<bits/stdc++.h>
using namespace std;
int num[100050] , maxN[100050];
int main(){
	int n , m = 0;
	cin >> n;
	for(int i = 0 ; i - n ; i++)
	{
		scanf("%d" , &num[i]);
		if(i && num[i] >= num[i - 1])
			maxN[i] = maxN[i - 1];
		maxN[i]++;
		m = max(maxN[i] , m);
	}
	cout << m;
	return 0;
}