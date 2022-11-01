#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=2333;
int n,s[N];
std::vector<int>ans;
void add(int n){
	std::reverse(s+1,s+n+1);
	ans.push_back(n);
}
int locate(int x){
	int t=1;
	while(s[t]!=x)t++;
	return t;
}
void solve(int n){
	if(n==3){
		if(s[1]!=1)add(3);
		return;
	}
	int a=locate(n-1),b=locate(n);
	if(b!=1){
		add(b),a=locate(n-1),b=locate(n);
	}
	if(a!=2){
		add(a-1);
		add(a+1);
		add(3);
		a=locate(n-1),b=locate(n);
	}
	assert(a==2&&b==1);
	add(n);
	solve(n-2);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		bool flag=1;
		for(int i=1;i<=n;i+=2)flag&=s[i]%2!=0;
		if(!flag){
			puts("-1");
			continue;
		}
		ans.clear();
		solve(n);
		printf("%d\n",ans.size());
		for(int x:ans)printf("%d ",x);
		puts("");
	}
}