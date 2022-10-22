#include<bits/stdc++.h>
using namespace std;
const int M=1e6+9;
int n;
int a[M],p[M];
void work(){
	int x,y;
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),a[i]=i-x,p[i]=0;
	for(x=1;!p[a[x]];p[a[x]]=x,x=a[x]);
	vector<int>ans;
	for(y=x,x=a[x];ans.push_back(y),y!=x;y=p[y]);
	printf("%d\n",ans.size());
	for(auto o:ans)printf("%d ",o);
	puts("");
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}