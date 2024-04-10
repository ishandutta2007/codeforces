#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

int n,m,ka,kb,cnt[200001];
bool vis[200001];
std::set<int>set;
int main(){
	scanf("%d%d%d%d",&n,&m,&ka,&kb);
	if(ka>m-1||kb>n-1){puts("No");return 0;}
	std::vector<int>a(ka),b(kb),c;
	for(int i=0;i<ka;i++)scanf("%d",&a[i]);
	for(int i=0;i<kb;i++)scanf("%d",&b[i]);
	std::reverse(a.begin(),a.end());
	for(int i=ka;i<m-1;i++)a.push_back(a.back());
	for(int i=kb;i<n-1;i++)b.push_back(b.back());
	for(int i=0;i<m-1;i++){
		if(!vis[a[i]]&&i)c.push_back(b.back()),b.pop_back();
		vis[a[i]]=1;
		c.push_back(a[i]);
	}
	while(!b.empty())c.push_back(b.back()),b.pop_back();
	std::reverse(c.begin(),c.end());
	puts("Yes");
	for(int i=0;i<n+m-2;i++)++cnt[c[i]];
	for(int i=1;i<=n+m;i++)if(!cnt[i])set.insert(i);
	for(int i=0;i<n+m-2;i++){
		printf("%d %d\n",*set.begin(),c[i]);
		set.erase(set.begin());
		if(!(--cnt[c[i]]))set.insert(c[i]);
	}
	printf("%d %d\n",*set.begin(),*set.rbegin());
}