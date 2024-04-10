#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n,m;
int a[Maxn+5];
int pre[Maxn+5],nxt[Maxn+5],pos[Maxn+5];
int to_l[Maxn+5],to_r[Maxn+5];
int d[Maxn+5],d_len;
struct Segment{
	int l,r;
}seg[Maxn+5];
int seg_len;
int mn_l[Maxn+5];
struct Del_Queue{
	std::priority_queue<int,std::vector<int>,std::greater<int> > q,p;
	void clear(){
		while(!q.empty()){
			q.pop();
		}
		while(!p.empty()){
			p.pop();
		}
	}
	void push(int x){
		q.push(x);
	}
	void pop(int x){
		p.push(x);
		while(!p.empty()&&p.top()==q.top()){
			p.pop(),q.pop();
		}
	}
	int top(){
		if(q.empty()){
			return Inf;
		}
		return q.top();
	}
}q;
void solve(){
	d_len=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[++d_len]=a[i];
	}
	for(int i=1;i<=n;i++){
		pos[i]=0;
	}
	std::sort(d+1,d+1+d_len);
	d_len=std::unique(d+1,d+1+d_len)-d-1;
	for(int i=1;i<=n;i++){
		a[i]=std::lower_bound(d+1,d+1+d_len,a[i])-d;
		pre[i]=pos[a[i]],pos[a[i]]=i;
		to_l[i]=std::max(to_l[i-1],pre[i]);
	}
	for(int i=1;i<=n;i++){
		pos[i]=n+1;
	}
	to_r[n+1]=n+1;
	for(int i=n;i>0;i--){
		nxt[i]=pos[a[i]],pos[a[i]]=i;
		to_r[i]=std::min(to_r[i+1],nxt[i]);
	}
	int min_r=1,max_l=n;
	seg_len=0;
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		if(to_l[r]<l){
			continue;
		}
		min_r=std::max(min_r,to_l[r]),max_l=std::min(max_l,to_r[l]);
		seg_len++,seg[seg_len].l=l,seg[seg_len].r=r;
	}
	m=seg_len;
	if(m==0){
		puts("0");
		return;
	}
	for(int i=1;i<=n;i++){
		mn_l[i]=n+1;
	}
	for(int i=1;i<=m;i++){
		mn_l[seg[i].r]=std::min(mn_l[seg[i].r],seg[i].l);
	}
	for(int i=n-1;i>0;i--){
		mn_l[i]=std::min(mn_l[i],mn_l[i+1]);
	}
	for(int i=1;i<=n;i++){
		pos[i]=0;
	}
	for(int i=1;i<max_l;i++){
		pos[a[i]]=i;
	}
	q.clear();
	for(int i=min_r+1;i<=n;i++){
		if(pre[i]>min_r){
			break;
		}
		if(pos[a[i]]>=mn_l[i]){
			q.push(pos[a[i]]);
		}
	}
	int ans=n;
	for(int i=min_r;i<=n;i++){
		if(pre[i]>min_r){
			break;
		}
		if(i>min_r&&pos[a[i]]>=mn_l[i]){
			q.pop(pos[a[i]]);
		}
		ans=std::min(ans,i-std::min(max_l,q.top())+1);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}