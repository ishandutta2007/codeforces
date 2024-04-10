#include<bits/stdc++.h>
typedef long long ll;
const int MAXQ=1000;
int Q;
std::map<ll,ll>cost;
template<class T>void swap(T&a,T&b){
	T c=a;
	a=b;
	b=c;
}
void update(ll u,ll v,int w){
	while(u!=v){
		if(u<v)
			swap(u,v);
		cost[u]+=w;
		u>>=1;
	}
}
ll query(ll u,ll v){
	ll ans=0;
	while(u!=v){
		if(u<v)
			swap(u,v);
		ans+=cost[u];
		u>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&Q);
	for(int i=1;i<=Q;++i){
		int opt;
		scanf("%d",&opt);
		ll u,v;
		int w;
		switch(opt){
			case 1:
				scanf("%I64d%I64d%d",&u,&v,&w);
				update(u,v,w);
				break;
			case 2:
				scanf("%I64d%I64d",&u,&v);
				printf("%I64d\n",query(u,v));
				break;
		}
	}
	return 0;
}