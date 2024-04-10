#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,id[2005005],w[2005005],it,fa[2005005],mp[2005005],a[400505],res;

int ty[400005],ql[400005],qr[400005],ql1[400005],qr1[400005],qw1[400005],ql2[400005],qr2[400005],qw2[400005];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
set<int> s;
void add(int x){if(!id[x]){id[x]=++it;fa[it]=it;w[it]=x;s.insert(x);}}
void fuck(int l,int r,int x){
	if(l>r)return;
	int i,j,k;
	add(x);
	while(!s.empty()){
		auto it=s.lower_bound(l);
		if(it==s.end())break;
		k=*it;
		if(k>r)break;
		s.erase(k);fa[id[k]]=id[x];id[k]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		mp[++it]=a[i];
	}
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>ty[i];
		if(ty[i]==1){
			cin>>ql[i]>>qr[i];
			mp[++it]=qr[i];
		}
		else if(ty[i]==2)cin>>ql[i];
		else if(ty[i]==3){
			cin>>ql[i]>>qr[i];
			mp[++it]=ql[i]-1;
			mp[++it]=qr[i]+1;
		}
	}
	sort(mp+1,mp+it+1);
	m=unique(mp+1,mp+it+1)-mp-1;
	mp[++m]=2e9;
	for(i=1;i<=n;i++)a[i]=lower_bound(mp+1,mp+m+1,a[i])-mp;
	for(i=1;i<=t;i++){
		if(ty[i]==1){
			qr[i]=lower_bound(mp+1,mp+m+1,qr[i])-mp;
		}
		else if(ty[i]==3){
			int md=(ql[i]+qr[i])/2;
			ql1[i]=lower_bound(mp+1,mp+m+1,ql[i])-mp;qr1[i]=upper_bound(mp+1,mp+m+1,md)-mp-1;qw1[i]=lower_bound(mp+1,mp+m+1,ql[i]-1)-mp;
			ql2[i]=lower_bound(mp+1,mp+m+1,md+1)-mp;qr2[i]=upper_bound(mp+1,mp+m+1,qr[i])-mp-1;qw2[i]=lower_bound(mp+1,mp+m+1,qr[i]+1)-mp;
		}
	}
	it=0;
	for(i=1;i<=n;i++)add(a[i]);
	for(i=1;i<=n;i++)a[i]=id[a[i]];
	for(i=1;i<=t;i++){
		if(ty[i]==1){
			add(qr[i]);
			a[ql[i]]=id[qr[i]];
		}
		else if(ty[i]==2){
			res=find(a[ql[i]]);
			cout<<mp[w[res]]<<'\n';
		}
		else if(ty[i]==3){
			fuck(ql1[i],qr1[i],qw1[i]);
			fuck(ql2[i],qr2[i],qw2[i]);
		}
	}
}