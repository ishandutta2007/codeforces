#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN];

int main(){
	int n, m;
	cin>>n>>m;
	int ans = 0;
	for(int i = 1; i <= m; i++)	{
		scanf("%d%d", &a[i], &b[i]);
	}
	int flag = 1;
	for(int i = 2; i <= m; i++){
		if (abs(a[i] - a[i-1]) < abs(b[i] - b[i-1])){
			flag = 0;
			break;
		}
		else{
			ans = max(ans, (abs(a[i] - a[i-1]) - abs(b[i] - b[i-1])) / 2 + max(b[i], b[i-1]));
		}
	}
	ans = max(ans, b[m] + (n - a[m]));
	ans = max(ans, b[1] + a[1] - 1);
	if (flag){
		cout<<ans<<endl;
	}
	else
		puts("IMPOSSIBLE");
	return 0;
}