#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
struct node{
	int m,p; ll r,d;
} a[510000];
int n,sx,sy; bool vis[510000];
int cnt,num[510000];
int head,tail,que[510000];
priority_queue<pii,vector<pii>,greater<pii> > q[260000];
void add(int x,pii v){
	for (;x<=cnt;x+=x&-x) q[x].push(v);
}
void upd(int x,ll v){
	for (;x;x-=x&-x)
		while (!q[x].empty()&&q[x].top().first<=v){
			if (!vis[q[x].top().second]){
				que[++tail]=q[x].top().second;
				vis[q[x].top().second]=true;
			}
			q[x].pop();
		}
}
int main(){
	scanf("%d%d%d%lld%d",&sx,&sy,&a[0].p,&a[0].r,&n);
	a[0].r*=a[0].r; int x,y;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d%d%lld",&x,&y,&a[i].m,&a[i].p,&a[i].r); num[i]=a[i].m;
		a[i].r*=a[i].r; a[i].d=1ll*(x-sx)*(x-sx)+1ll*(y-sy)*(y-sy);
	}
	sort(num+1,num+n+1); cnt=unique(num+1,num+n+1)-num-1;
	for (int i=1;i<=n;i++){
		a[i].m=lower_bound(num+1,num+cnt+1,a[i].m)-num;
		add(a[i].m,pii(a[i].d,i));
	}
	head=0; tail=0; que[1]=0; vis[0]=true;
	while (head<=tail){
		int u=que[head++];
		int x=upper_bound(num+1,num+cnt+1,a[u].p)-num-1;
		upd(x,a[u].r);
	}
	printf("%d\n",tail);
	return 0;
}