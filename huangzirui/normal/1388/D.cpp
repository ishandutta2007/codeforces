#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const ll maxn=200010;
ll i,j,k,n,m,sum[maxn],to[maxn],rd[maxn];
vector<ll>last[maxn];
vector<ll>Ans;
queue<ll>Q;
ll ans;
void out(ll now){
	for(ll i=0;i<last[now].size();i++){
		ll u=last[now][i];
		printf("%lld ",u);
		out(u);
	}
}
int main(){
	n=read();
	for(i=1;i<=n;i++)sum[i]=read();
	for(i=1;i<=n;i++){
		to[i]=read();
		if(to[i]!=-1)rd[to[i]]++;
	}
	for(i=1;i<=n;i++)if(!rd[i])Q.push(i);
	while(!Q.empty()){
		ll now=Q.front();Q.pop();
		rd[to[now]]--;
		ans+=sum[now];
		if(to[now]==-1 || sum[now]>0){
			if(to[now]!=-1)sum[to[now]]+=sum[now];
			Ans.push_back(now);
		}
		else last[to[now]].push_back(now);
		if(!rd[to[now]])Q.push(to[now]);
	}cout<<ans<<endl;
	for(i=0;i<Ans.size();i++){
		printf("%lld ",Ans[i]);
		out(Ans[i]);
	}cout<<endl;
	return 0;
}