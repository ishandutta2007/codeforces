#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
#define inf 1000000000000000ll
using namespace std;
typedef long long ll;
struct node{int f[2],t,cur;}a[100005];
int cmpt(int i,int j){return a[i].t<a[j].t;}
struct cmp{int operator()(int i,int j){return a[i].f[a[i].cur]<a[j].f[a[j].cur];}};
int n,m;
int ordt[100005],it;
multiset<int,cmp>s;
ll ans[100005];
int bit[200005]={0};
void upd(int i,int x){for (;i<=m;i+=i&-i)bit[i]+=x;}
int que(int i){int ans=0;for(;i;i-=i&-i)ans+=bit[i];return ans;}
int main()
{
	ll t=0;int cur=1,dir=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d%d%d",&a[i].t,&a[i].f[0],&a[i].f[1]),ordt[i]=i;
	sort(ordt+1,ordt+1+n,cmpt);
	it=0;
	while(1){
		ll tt=it<n?a[ordt[it+1]].t-t:inf;
		ll t1=t;int i;
		multiset<int,cmp>::iterator itr;
		if(dir==1){
			a[0].f[0]=cur;itr=s.lower_bound(0);
			if(itr!=s.end())t1=a[*itr].f[a[*itr].cur]-cur;
			else t1=inf;
		}else if(dir==-1){
			a[0].f[0]=cur;itr=s.upper_bound(0);
			if(itr!=s.begin()){
				itr--;
				t1=cur-a[*itr].f[a[*itr].cur];
			}else t1=inf;
		}else t1=inf;
		if(t1==inf && tt==inf)break;
		if(tt<t1){
			t+=tt;it++;
			cur+=dir*tt;
			upd(a[ordt[it]].f[0],1);
			s.insert(ordt[it]);
		}else{
			int i=*itr;
			t+=t1;cur+=dir*t1;
			if(a[i].cur==0){
				upd(a[i].f[0],-1);
				upd(a[i].f[1],1);
				s.erase(itr);
				a[i].cur=1;
				s.insert(i);
			}else{
				upd(a[i].f[1],-1);
				s.erase(itr);
				ans[i]=t;
				a[i].cur=2;
			}
		}
		int pup=que(m)-que(cur),pdown=que(cur);
		if(pup==0 && pdown==0)dir=0;
		else if(pup>=pdown) dir=1;
		else dir=-1;
	}
	for (int i=1;i<=n;i++)printf("%I64d\n",ans[i]);	
	return 0;
}