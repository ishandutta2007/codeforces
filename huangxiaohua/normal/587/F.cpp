#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,it1,w,fa[200500],n0,f1[200500];
int l,r;
string st,s0[100500];

vector<int> v[100500],tmp,tmp2;
queue<int> q;

vector<tuple<int,int,int> >qu[100500];

ll f[100500],res[100500],ans;

void add(int x,int y){
	for(;x<=n;x+=(-x&x)){f[x]+=y;}
}
ll get(int x,ll y=0){
	for(;x;x-=(-x&x)){y+=f[x];}return y;
}

struct sb{
	int fail,mp[30];
	int num,ty;
	vector<int> v;
	bool vis;
}s[100500];

void dfs(int x){
	for(auto i:v[x]){
		if(s[i].vis)dfs(i);
		s[x].num+=s[i].num;
	}
	tmp2.push_back(x);
	if(s[x].ty){
		tmp.push_back(x);
	}
	else{
		for(auto i:s[x].v){
			add(i,s[x].num);
		}
	}
}

map<string,int> mp2;
int idx[200500];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t;
	for(i=1;i<=n;i++){
		cin>>st;it=0;
		mp2[st]=i;
		s0[i]=st;
		for(auto j:st){
			k=j-'a'+1;
			if(!s[it].mp[k]){s[it].mp[k]=++it1;}
			it=s[it].mp[k];
		}
		s[it].v.push_back(i);
	}
	for(i=1;i<=n;i++){
		idx[i]=mp2[s0[i]];
	}
	for(i=1;i<=26;i++){
		if(s[0].mp[i]){q.push(s[0].mp[i]);}
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		v[s[x].fail].push_back(x);
		fa[x]=s[x].fail;
		for(i=1;i<=26;i++){
			if(s[x].mp[i]){
				it=s[x].fail;
				while(it&&!s[it].mp[i]){it=s[it].fail;}
				s[s[x].mp[i]].fail=s[it].mp[i];
				q.push(s[x].mp[i]);
			}
		}
	}
	it=n+5;
	for(i=1;i<=it1;i++){
		if(s[i].v.size()>=100){
			s[i].ty=1;
			j=0;
			for(auto k:s[i].v){
				f1[k]=j;j++;
			}
			s[i].v.push_back(++it);
			f1[it]=j;
		}
	}
	for(i=1;i<=t;i++){
		cin>>l>>r>>w;
		w=idx[w];
		qu[w].push_back({i,l,r});
	}
	for(i=1;i<=n;i++){
		if(qu[i].empty())continue;
		memset(f,0,sizeof(f));
		it=0;
		s[0].vis=1;
		for(auto j:s0[i]){
			k=j-'a'+1;
			while(it&&!s[it].mp[k]){it=s[it].fail;}
			it=s[it].mp[k];
			s[it].num++;
			k=it;
			while(!s[k].vis){
				s[k].vis=1;k=fa[k];
			}
		}
		tmp.clear();
		tmp2.clear();
		dfs(0);
		for(auto [id,l,r]:qu[i]){
			ans=get(r)-get(l-1);
			for(auto x:tmp){
				int y=*upper_bound(s[x].v.begin(),s[x].v.end(),r);
				ans+=1ll*f1[y]*s[x].num;
				y=*upper_bound(s[x].v.begin(),s[x].v.end(),l-1);
				ans-=1ll*f1[y]*s[x].num;
			}
			res[id]=ans;
		}
		for(auto i:tmp2){
			s[i].num=s[i].vis=0;
		}
	}
	
	for(i=1;i<=t;i++){
		cout<<res[i]<<'\n';
	}
}