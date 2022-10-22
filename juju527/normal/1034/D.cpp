//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector
#define eb emplace_back
using namespace std;
const int maxn=3e5+5;
int n,k,len;
struct seg{int l,r;}a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int buf[2*maxn],sum[2*maxn];
set<pii> s;
vec<pii> I[maxn];
void init(){
	s.insert(pii(1,0));
	s.insert(pii(len+1,n+1));
	for(int i=1;i<=n;i++){
		int l=a[i].l,r=a[i].r;
		auto it=s.upper_bound(pii(l,n+1));
		if((*it).fi>r){
			int p=(*it).fi;
			it--;int co=(*it).se;
			I[i].eb(pii(co+1,sum[r]-sum[l-1]));
			if((*it).fi==l)s.erase(it);
			s.insert(pii(l,i));
			if(r<p-1)s.insert(pii(r+1,co));
			continue;
		}
		it--;int co=(*it).se;
		if((*it).fi==l){
			auto tmp=it;it++;
			s.erase(tmp);
		}
		else it++;
		I[i].eb(pii(co+1,sum[(*it).fi-1]-sum[l-1]));
		while(it!=s.end()){
			pii p=*it;
			auto tmp=it;it++;
			s.erase(tmp);
			if((*it).fi<=r+1){
				I[i].eb(pii(p.se+1,sum[(*it).fi-1]-sum[p.fi-1]));
				if((*it).fi==r+1)break;
			}
			else{
				s.insert(pii(r+1,p.se));
				I[i].eb(pii(p.se+1,sum[r]-sum[p.fi-1]));
				break;
			}
		}
		s.insert(pii(l,i));
	}
	return ;
}
int f[maxn];
ll calc_num(int v){
	for(int i=1;i<=n;i++)f[i]=0;
	ll num=0;
	int pos=0;
	for(int i=1;i<=n;i++){
		for(auto p:I[i]){
			int x=p.fi,v=p.se;
			x=max(x,pos);
			f[x]+=v;f[i+1]-=v;
		}
		while(pos+1<=i&&f[pos+1]+f[pos]>=v)++pos,f[pos]+=f[pos-1];
		num+=pos;
	}
	return num;
}
ll calc_sum(int v){
	for(int i=1;i<=n;i++)f[i]=0;
	ll sum=0,res=0;
	int pos=0;
	for(int i=1;i<=n;i++){
		for(auto p:I[i]){
			int x=p.fi,v=p.se;
			if(x<=pos)sum+=1ll*v*(pos-x+1);
			x=max(x,pos);
			f[x]+=v;f[i+1]-=v;
		}
		while(pos+1<=i&&f[pos+1]+f[pos]>=v)++pos,f[pos]+=f[pos-1],sum+=f[pos];
		res+=sum;
	}
	return res;
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i].l=read(),a[i].r=read();
		buf[++len]=a[i].l,buf[++len]=a[i].r;
	}
	sort(buf+1,buf+len+1);
	len=unique(buf+1,buf+len+1)-buf-1;
	for(int i=2;i<=len;i++)sum[i-1]=buf[i]-buf[1];
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(buf+1,buf+len+1,a[i].l)-buf;
		a[i].r=lower_bound(buf+1,buf+len+1,a[i].r)-buf-1;
	}
	init();
	int l=0,r=1e9;
	while(l+1<r){
		int mid=l+((r-l)>>1);
		if(calc_num(mid)<k)r=mid;
		else l=mid;
	}
	printf("%lld\n",calc_sum(r)+1ll*l*(k-calc_num(r)));
    return 0;
}