#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 6000
//
int i,j,k,n,m,t,op[100500],a[100500],cl[100500],cr[100500],it,id[100500],lst[100500],l,r,sb;
pair<int,int> op1[100500],op2[100500];
ll res[100500],cur;

struct SB{
	int id,l,r,t;
	bool operator<(const SB a)const{
		if((l/N)!=(a.l/N))return l<a.l;
		if((r/N)!=(a.r/N))return r<a.r;
		return t<a.t;
	}
}q[100500];

set<int> s[100500];

struct JB{
	int l,r,val;
}lb[1005000];

void add_lb(int x,int y){
	lb[x].r=y;lb[y].l=x;
}

void del_lb(int x){
	lb[lb[x].r].l=lb[x].l;
	lb[lb[x].l].r=lb[x].r;
}

void upd(int x){
	cur-=max(0,lb[cr[x]].val-lb[cl[x]].val);
	while(lb[cl[x]].val<l)cl[x]=lb[cl[x]].r;
	while(lb[cl[x]].l&&lb[lb[cl[x]].l].val>=l)cl[x]=lb[cl[x]].l;
	while(lb[cr[x]].val>r)cr[x]=lb[cr[x]].l;
	while(lb[cr[x]].r&&lb[lb[cr[x]].r].val<=r)cr[x]=lb[cr[x]].r;
	cur+=max(0,lb[cr[x]].val-lb[cl[x]].val);
}

void add1(pair<int,int> p){
	auto [x,y]=p;
	cur-=max(0,lb[cr[y]].val-lb[cl[y]].val);
	add_lb(x,lb[x].r);add_lb(lb[x].l,x);
	if(lb[cl[y]].l==x&&lb[x].val>=l)cl[y]=x;
	if(lb[cr[y]].r==x&&lb[x].val<=r)cr[y]=x;
	cur+=max(0,lb[cr[y]].val-lb[cl[y]].val);
}

void del1(pair<int,int> p){
	auto [x,y]=p;
	cur-=max(0,lb[cr[y]].val-lb[cl[y]].val);
	if(cl[y]==x)cl[y]=lb[cl[y]].r;
	if(cr[y]==x)cr[y]=lb[cr[y]].l;
	cur+=max(0,lb[cr[y]].val-lb[cl[y]].val);
	del_lb(x);
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>t;
	for(i=1;i<=n;i++){
		lb[i*2-1].r=i*2;
		lb[i*2].l=i*2-1;
		lb[i*2].val=n+5;
		lst[i]=i*2-1;
	}
	it=n*2;
	for(i=1;i<=n;i++){
		cin>>a[i];
		id[i]=++it;
		lb[it].val=i;
		add_lb(it,lb[lst[a[i]]].r);
		add_lb(lst[a[i]],it);
		lst[a[i]]=it;
		s[a[i]].insert(i);
	}
	for(i=1;i<=t;i++){
		int l,r,ty;
		cin>>ty>>l>>r;
		if(ty==1){
			if(r==a[l])continue;
			op[++j]=l;
			op1[j]={id[l],a[l]};
			lb[++it].val=l;
			del_lb(id[l]);s[a[l]].erase(l);
			a[l]=r;
			id[l]=it;
			s[r].insert(l);
			auto it1=s[r].upper_bound(l);
			if(it1==s[r].end())sb=lb[r*2].l,add_lb(it,r*2);
			else sb=lb[id[*it1]].l,add_lb(it,id[*it1]);
			add_lb(sb,it);
			op2[j]={it,r};
		}
		else{
			q[++k]={k,l,r,j};
		}
	}
	for(i=1;i<=n;i++){
		cr[i]=i*2-1;
		cl[i]=lb[i*2-1].r;
	}
	t=k;
	sort(q+1,q+t+1);
	l=1;r=0;k=j;
	for(i=1;i<=t;i++){
		while(k<q[i].t){
			k++;
			del1(op1[k]);add1(op2[k]);
			a[op[k]]=op2[k].second;
		}
		while(k>q[i].t){
			del1(op2[k]);add1(op1[k]);
			a[op[k]]=op1[k].second;
			k--;
		}
		while(l>q[i].l){l--;sb=a[l];upd(sb);}
		while(r<q[i].r){r++;sb=a[r];upd(sb);}
		while(l<q[i].l){sb=a[l];l++;upd(sb);}
		while(r>q[i].r){sb=a[r];r--;upd(sb);}
		res[q[i].id]=cur;
	}
	for(i=1;i<=t;i++){
		cout<<res[i]<<'\n';
	}
}