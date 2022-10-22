#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,Q,p[1100000],l[1100000];
int top,s[1100000]; ll Ans[1100000];
vector<int> vec[1100000];
priority_queue<pii> que;
struct node{
	int l,r;
	bool operator<(const node &a) const{
		return l<a.l||(l==a.l&&r<a.r);
	}
} q[1100000]; pll tree[1100000];
void add(int x,pll v){
	for (;x<=n;x+=x&-x) tree[x].first+=v.first,tree[x].second+=v.second;
}
pll query(int x){
	pll res=pll(0,0);
	for (;x;x-=x&-x) res.first+=tree[x].first,res.second+=tree[x].second;
	return res;
}
void solve(){
	for (int i=1;i<=n;i++) tree[i]=pll(0,0),vec[i].clear();
	top=1; s[1]=0;
	for (int i=1;i<=n;i++){
		while (top>1&&p[s[top]]<p[i]) top--;
		l[i]=s[top]+1; s[++top]=i;
	}
	for (int i=1;i<=Q;i++)
		vec[q[i].l].push_back(i);
	for (int i=n;i>=1;i--){
		que.push(pii(l[i],i)); add(i,pll(0,1));
		while (!que.empty()&&que.top().first==i){
			int u=que.top().second; que.pop();
			add(u,pll(i,-1));
		}
		for (int v:vec[i]){
			pll tmp=query(q[v].r);
			Ans[v]+=tmp.first+tmp.second*i;
		}
	}
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=Q;i++) scanf("%d",&q[i].l);
	for (int i=1;i<=Q;i++) scanf("%d",&q[i].r);
	
	solve();
//	for (int i=1;i<=Q;i++) cerr<<Ans[i]<<' '; cerr<<'\n';
	reverse(p+1,p+n+1);
	for (int i=1;i<=Q;i++){
		q[i].l=n-q[i].l+1; q[i].r=n-q[i].r+1;
		swap(q[i].l,q[i].r);
	}
	solve();
	for (int i=1;i<=Q;i++) printf("%lld ",1ll*(n+2)*(q[i].r-q[i].l+1)-Ans[i]);
	return 0;
}
/*
 * [L,R]
 * [L,R]
 * 
 * [l_i,r_i]
 * l_ii+11r_ii-1n
 * [L,R][max(L,l_i),min(R,r_i)]
 * 
 * [L,R]imin(R,r_i)-max(L,l_i)+1
 * max(L,l_i)min(R,r_i)
 * Li>=Lmax(L,l_i)
 * setsetl_i>Li
 * */