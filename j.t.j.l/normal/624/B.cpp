#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int a[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n;i ++)
		scanf("%d", &a[i]);
	sort(a + 1, a +  n +  1);
	long long ans = 0;
	long long now = a[n] + 1;
	for(int i = n; i >= 1; i--){
		now--;
		if (a[i] > now)
			a[i] = now;
		ans += max(a[i], 0);
		now = a[i];
	}
	cout<<ans<<endl;
	return 0;
}