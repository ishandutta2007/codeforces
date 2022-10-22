#include<bits/stdc++.h>
using namespace std;
const int M=3e5+9;
int n;
int h[M],dp[M];
stack<int>s,t;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&h[i]);
		dp[i]=dp[i-1]+1;
		while(!s.empty()&&h[s.top()]>h[i])dp[i]=min(dp[i],dp[s.top()]+1),s.pop();
		while(!t.empty()&&h[t.top()]<h[i])dp[i]=min(dp[i],dp[t.top()]+1),t.pop();
		if(!s.empty())dp[i]=min(dp[i],dp[s.top()]+1);
		if(!t.empty())dp[i]=min(dp[i],dp[t.top()]+1);
		if(!s.empty()&&h[s.top()]==h[i])s.pop();
		if(!t.empty()&&h[t.top()]==h[i])t.pop();
		s.push(i);
		t.push(i);
	}
	printf("%d\n",dp[n]-1);
	return 0;
}