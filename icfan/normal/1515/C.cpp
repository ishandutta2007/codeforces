#include <queue>
#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n,m,x;
int h[Maxn+5];
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > > q;
void solve(){
	while(!q.empty()){
		q.pop();
	}
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=m;i++){
		q.push(std::make_pair(0,i));
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		std::pair<int,int> tmp=q.top();
		q.pop();
		printf("%d ",tmp.second);
		tmp.first+=h[i];
		q.push(tmp);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}