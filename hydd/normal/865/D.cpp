#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll ans;
priority_queue<int,vector<int>,greater<int>> que;
int main(){
	scanf("%d",&n); int x;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		que.push(x);
		if (que.top()<x){
			ans+=x-que.top(); que.pop();
			que.push(x);
		}
	}
	printf("%lld\n",ans);
	return 0;
}