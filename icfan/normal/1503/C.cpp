#include <queue>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int n;
struct Node{
	int a,c;
}a[Maxn+5];
bool vis[Maxn+5];
bool cmp_Node(Node a,Node b){
	return a.a+a.c<b.a+b.c;
}
struct Del_Queue{
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > > p,q;
	void make_small(){
		while(!q.empty()&&q.top()==p.top()){
			p.pop();
			q.pop();
		}
	}
	void push(std::pair<int,int> a){
		p.push(a);
		make_small();
	}
	std::pair<int,int> top(){
		make_small();
		return p.top();
	}
	void pop(std::pair<int,int> a){
		q.push(a);
		make_small();
	}
	bool empty(){
		make_small();
		return p.empty();
	}
}q;
int main(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].a,&a[i].c);
		sum+=a[i].a+a[i].c;
	}
	std::sort(a+1,a+1+n,cmp_Node);
	ll ans=a[1].a;
	int lst=a[1].a+a[1].c;
	vis[1]=1;
	for(int i=2;i<=n;i++){
		q.push(std::make_pair(a[i].a,i));
	}
	int pos=2;
	while(!q.empty()){
		int t=q.top().second;
		vis[t]=1;
		ans+=std::min(a[t].a,lst);
		lst=a[t].a+a[t].c;
		for(int i=pos;i<=t;i++){
			q.pop(std::make_pair(a[i].a,i));
		}
		pos=t+1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans+=a[i].a;
		}
	}
	printf("%lld\n",sum-ans);
	return 0;
}