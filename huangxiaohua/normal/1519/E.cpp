#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,it2,used[500500],u2[500500];
ll t1,t2,t3,t4,t5;
struct sb{
	ll a,b,c,d;
	ll k1,k2,k3,k4;
	int t1,t2;
}s[500500];

unordered_map<ll,unordered_map<ll,int> >mp;
vector<int> v[500500],v2[500500];
stack<pair<int,int> >res;

void dfs(int x,int fa){
	u2[x]=1;
	int tmp1=0,tmp2=0,tmp3=0;
	for(auto i:v2[x]){
		if(!u2[i]){dfs(i,x);}
	}
	k=0;
	for(auto i:v[x]){
		if(!used[i]){k^=1;}
	}
	for(auto i:v[x]){
		if(k&&(s[i].t1==fa||s[i].t2==fa)){tmp3=i;break;}
	}
	for(auto i:v[x]){
		if(used[i]||tmp3==i){continue;}
		if(!tmp1){tmp1=i;}
		else{tmp2=i;}
		if(tmp1&&tmp2){
			res.push({tmp1,tmp2});
			used[tmp1]=used[tmp2]=1;
			tmp1=tmp2=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	u2[0]=1;
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c,&s[i].d);
		
		t1=s[i].a;t2=s[i].b;t3=s[i].c;t4=s[i].d;
		t1+=t2;
		t1=t1*t4;
		t2=t2*t3;
		t5=__gcd(t1,t2);
		t1/=t5;t2/=t5;
		s[i].k1=t1;s[i].k2=t2;
		if(!mp[t1][t2]){mp[t1][t2]=++it;}
		v[mp[t1][t2]].push_back(i);
		s[i].t1=mp[t1][t2];
		
		t1=s[i].a;t2=s[i].b;t3=s[i].c;t4=s[i].d;
		t3+=t4;
		t1=t1*t4;
		t2=t2*t3;
		t5=__gcd(t1,t2);
		t1/=t5;t2/=t5;
		s[i].k1=t1;s[i].k2=t2;
		if(!mp[t1][t2]){mp[t1][t2]=++it;}
		v[mp[t1][t2]].push_back(i);
		s[i].t2=mp[t1][t2];
	}
	for(i=1;i<=n;i++){
		if(v[s[i].t1].size()==1){
			s[i].t1=0;
		}
		if(v[s[i].t2].size()==1){
			s[i].t2=0;
		}
		if(s[i].t1&&s[i].t2){
			v2[s[i].t2].push_back(s[i].t1);
			v2[s[i].t1].push_back(s[i].t2);
		}
	}
	for(i=1;i<=it;i++){
		if(u2[i]||v[i].size()<=1){continue;}
		dfs(i,0);
	}
	printf("%d\n",res.size());
	while(!res.empty()){
		int u=res.top().first,v=res.top().second;
		res.pop();
		printf("%d %d\n",u,v);
	}
}