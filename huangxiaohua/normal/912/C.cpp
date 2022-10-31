#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t;
ll atk,bo0,bo1,id[100500];
ll st[100500],d[100500],sb,ti[109050],en[100500],hel[100500],res,num,tmp;
bool die[100500];

struct sb{
	ll sid;
	int id,ty;
	bool operator <(const sb a)const{
		if(sid==a.sid)return id<a.id;
		return sid>a.sid;
	}
}s;
map<ll,set<struct sb> >mp;

int main(){
	scanf("%d%d",&n,&m);
	scanf("%lld%lld%lld",&bo0,&bo1,&atk);
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld",&sb,&st[i],&d[i]);
		if(sb<=atk&&bo1){puts("-1");return 0;}
		if(sb<=atk){die[i]=1;num++;}
	}
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&ti[i],&en[i],&hel[i]);
	}
	for(i=1;i<=n;i++){
		if(die[i])continue;
		if(st[i]<=atk){
			die[i]=1;num++;
			if(d[i]){
				s.id=i;s.ty=0;s.sid=0;
				tmp=(atk-st[i])/d[i]+1;
				mp[tmp].insert(s);
			}
		}
	}
	res=max(res,num*bo0);
	for(i=1;i<=m;i++){
		s.sid=ti[i];
		s.id=en[i];
		if(hel[i]>atk){
			s.ty=0;
			mp[ti[i]].insert(s);
		}
		else{
			s.ty=1;
			mp[ti[i]].insert(s);
			
			s.ty=0;
			if(d[en[i]])tmp=ti[i]+(atk-hel[i])/d[en[i]]+1;
			
			mp[tmp].insert(s);
		}
	}
	
	for(auto [sb,s]:mp){
		res=max(res,(sb*bo1-bo1+bo0)*num);
		for(auto [sid,x,y]:s){
			if(id[x]>sid)continue;
			id[x]=sid;
			
			num-=die[x];num+=y;
			die[x]=y;
		}
	}
	
	for(i=1;i<=n;i++){
		if(die[i]&&bo1){
			puts("-1");return 0;
		}
	}
	res=max(res,num*bo0);
	printf("%lld",res);
}