#include<bits/stdc++.h>
using namespace std;
int num[1001];
int main()
{
	int N , ans = 0;
	scanf("%d" , &N);
	for(int i = 1 ; i <= N ; i++)
		scanf("%d" , &num[i]);
	sort(num + 1 , num + N + 1);
	for(int i = 2 ; i <= N ; i++)
		ans += num[i] - num[i - 1] - 1;
	cout << ans;
 	return 0;
}