#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;

int f (int X) {
	int R = 0;
	for(int i=X;i;i/=10) R += i%10;
	return R;
}

int main()
{
	scanf("%d",&n);
	for(int i=max(1,n-100);i<=n;i++) {
		if(i+f(i) == n) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(auto &T : ans) printf("%d\n",T);
}