//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1005;
const ll inf=1000000000000000000ll;
pair<ll,ll> res[maxn];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
mt19937 rnd(random_device{}());
ll query(int i,ll x){
	printf("? %d %lld\n",i,x);fflush(stdout);
	return read();
}
ll calc(int i,ll v){
	ll l=0,r=inf+1;
	while(l+1<r){
		ll mid=(l+r)>>1;
		if(query(i,mid)<=v)l=mid;
		else r=mid;
	}
	return l;
}
ll devide(vec s,int n,int num,ll v){
	int len=s.size();
	int i=s[rnd()%len];
	ll pos=calc(i,v);
	vec lt,rt,aux;
	lt.clear();rt.clear();aux.clear();
	for(auto j:s){
		ll tmp=query(j,pos);
		if(tmp>v)lt.eb(j);
		else if(tmp<v)rt.eb(j);
		else aux.eb(j);
	}
	while(lt.size()<num&&aux.size())lt.eb(aux.back()),aux.pop_back();
	while(aux.size())rt.eb(aux.back()),aux.pop_back();
	if(lt.size()==num)return pos;
	if(lt.size()>num)return devide(lt,n,num,v);
	else return devide(rt,n,num-lt.size(),v);
}
void solve(vec s,ll lx,ll rx,ll l,ll r){
	int n=s.size();
	if(n==1){res[s[0]]=make_pair(lx,rx);return ;}
	ll d=(r-l)/n;
	ll mid=l+d*(n/2);
	ll pos=devide(s,s.size(),n/2,mid);
	vec lt,rt,aux;
	lt.clear();rt.clear();aux.clear();
	for(auto i:s){
		ll tmp=query(i,pos);
		if(tmp>mid)lt.eb(i);
		else if(tmp<mid)rt.eb(i);
		else aux.eb(i);
	}
	while(lt.size()<n/2&&aux.size())lt.eb(aux.back()),aux.pop_back();
	while(aux.size())rt.eb(aux.back()),aux.pop_back();
	solve(lt,lx,pos,l,mid);solve(rt,pos,rx,mid,r);
	return ;
}
int main(){
    int n;ll l;
	n=read();l=read();
	vec s;s.resize(n);
	for(int i=0;i<n;i++)s[i]=i+1;
	solve(s,0,inf,0,l);
	puts("!");fflush(stdout);
	for(int i=1;i<=n;i++){printf("%lld %lld\n",res[i].fi,res[i].se);fflush(stdout);}
    return 0;
}