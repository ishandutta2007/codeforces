#include<bits/stdc++.h>
using namespace std;

int n, a[1005];
vector<int> ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++) {
		bool F = false;
		for(int i=k+1;i<=n;i++) {
			if(a[i] - a[i-1] != a[i-k] - a[i-k-1]) {
				F = true;
				break;
			}
		}
		if(!F) ans.push_back(k);
	}
	printf("%d\n", (int) ans.size());
	for(auto &T : ans) printf("%d ",T);
}