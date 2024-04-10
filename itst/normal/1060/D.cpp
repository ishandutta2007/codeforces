#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

int numL[MAXN] , numR[MAXN];

int main(){
	int N;
	cin >> N;
	for(int i = 1 ; i <= N ; i++)
		cin >> numL[i] >> numR[i];
	sort(numL + 1 , numL + N + 1);
	sort(numR + 1 , numR + N + 1);
	long long ans = N;
	for(int i = 1 ; i <= N ; i++)
		ans += max(numL[i] , numR[i]);
	cout << ans;
	return 0;
}