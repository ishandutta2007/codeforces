#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n,m;
int main(){
	scanf("%d%d",&n,&m); int ans=0,x;
	for (int i=1;i<=m-1&&i<=n;i++){
		scanf("%d",&x);
		while (!q.empty()&&q.top()+i>=m) q.pop();
		if (max(x,i)<m) q.push(max(x-i,0));
		ans=max(ans,(int)q.size());
	}
	printf("%d\n",ans);
	return 0;
}