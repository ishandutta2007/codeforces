#include<bits/stdc++.h>
using namespace std;
vector<int> s,vec[1100000];
int n,a[1100000],b[1100000]; bool ok;
void dfs(int u){
	b[u^1]=1; b[u]=1; u^=1;
	while (!vec[a[u]].empty())
		if (b[vec[a[u]].back()]) vec[a[u]].pop_back();
		else dfs(vec[a[u]].back());
	ok=(ok&&(s.empty()||a[u]==a[s.back()]));
	s.push_back(u); s.push_back(u^1);
}
int main(){
	scanf("%d",&n); n<<=1;
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=20;i>=0;i--){
		int sta=(1<<i)-1;
		for (int j=n-1;j>=0;j--){
			b[j]=0; a[j]&=sta;
			vec[a[j]].push_back(j);
		}
		ok=true; s.clear(); dfs(0);
		if (ok&&(int)s.size()==n&&a[s.front()]==a[s.back()]){
			printf("%d\n",i);
			for (int j=(int)s.size()-1;j>=0;j--) printf("%d ",s[j]+1);
			break;
		}
		for (int j=0;j<=sta;j++) vec[j].clear();
	}
	return 0;
}