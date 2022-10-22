#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=4e6+99;

ll n,t,q,c,m,cnt,ans,FF,FL,a[N],b[N],lazy[N],fenS[N],fenC[N],s[N][2];
pair<ll,ll> seg[N],segb[N];
map<ll,ll> F1,F2;

void updateS(ll x,ll val) { ++x;  while(x<N)  {  fenS[x]+=val;  x+=(x&-x);  } }
ll queryS(ll x) {  ++x;  ll res=0;  while(x>0)  {  res+=fenS[x];  x-=(x&-x);  } return res; } 
void updateC(ll x,ll val) { ++x;  while(x<N)  {  fenC[x]+=val;  x+=(x&-x);  } }
ll queryC(ll x) {  ++x;  ll res=0;  while(x>0)  {  res+=fenC[x];  x-=(x&-x);  } return res; } 
ll Sum(ll l,ll r){ return queryS(r)-queryS(l-1); }
ll Cnt(ll l,ll r){ return queryC(r)-queryC(l-1); }

pair<ll,ll> merge(pair<ll,ll> u,pair<ll,ll> v){
	u.F+=v.F,u.S+=v.S;
	return u;
}
void shift(int id){
   seg[id*2+0].F+=lazy[id]*seg[id*2+0].S;
   seg[id*2+1].F+=lazy[id]*seg[id*2+1].S;
   lazy[id*2+0]+=lazy[id];
   lazy[id*2+1]+=lazy[id];
   lazy[id]=0;
}
void add(ll id, ll L, ll R, ll l, ll r, ll val){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      seg[id].F+=val*seg[id].S;
      return ;   
   }
   ll mid=(l+r)>>1;
   shift(id);
   add(id*2+0,L,R,l,mid,val);
   add(id*2+1,L,R,mid,r,val);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
ll query(ll id, ll L, ll R, ll l, ll r){
   if(r<=L || R<=l) return 0;
   if(L<=l && r<=R){
      return seg[id].F;
   }
   shift(id);
   ll mid=(l+r)>>1;
   return query(id*2+0,L,R,l,mid)+query(id*2+1,L,R,mid,r);
}
void Add_Del(ll x,ll val,ll s){
	ll u=1,bf=Cnt(1,x-1)+1,l=1,r=m;
	pair<ll,ll> p;
	cnt+=s;
	updateC(x,s*1);
	updateS(x,s*val);
	add(1,x+1,m,1,m,s*1);
	while(1){
		seg[u].F+=s*bf*val;
		seg[u].S+=s*val;
		segb[u].F+=s;
		segb[u].S+=s*val;
		shift(u);
		if(l+1==r) break;
		ll mid=(l+r)/2;
		if(x<mid) u=u*2,r=mid;
		else u=u*2+1,l=mid;
	}
}
////////////////////////////////////////////////////////////
void read(){
	cin>>n>>q;
	f(i,0,n){
		ll x;
		cin>>x;
		s[i][0]=1;
		s[i][1]=x;
		b[c++]=s[i][1];
	}
	//if(q>10000) q=0;
	f(i,n,n+q){
		cin>>s[i][0]>>s[i][1];
		b[c++]=s[i][1];
	}
	m=1;
	sort(b,b+c);
	f(i,0,c){
		if(i==0 || b[i]!=b[i-1]){
			F1[b[i]]=m;
			F2[c]=b[i];
			m++;
		}
	}
	m+=5;
	//eror(m);
}

pair<ll,ll> find_first(ll u=1,ll l=1,ll r=m){
	ll mid=(l+r)/2;
	pair<ll,ll> ans=mp(0,1),p1,p2;
	if(FF==0) return ans;
	if(segb[u].F<=FF){
		FF-=segb[u].F;
		ans.F=segb[u].S;
		ans.S=r;
		return ans;
	}
	p1=find_first(u*2+0,l,mid);
	p2=find_first(u*2+1,mid,r);
	return mp(p1.F+p2.F,max(p1.S,p2.S));
}
pair<ll,ll> find_last(ll u=1,ll l=1,ll r=m){
	ll mid=(l+r)/2;
	pair<ll,ll> ans=mp(0,m),p1,p2;
	if(FL==0) return ans;
	if(segb[u].F<=FL){
		FL-=segb[u].F;
		ans.F=segb[u].S;
		ans.S=l;
		return ans;
	}
	p2=find_last(u*2+1,mid,r);
	p1=find_last(u*2+0,l,mid);
	return mp(p1.F+p2.F,min(p1.S,p2.S));
}
void calc(){
	ll ans=0,u,v;
	ll l=1,r=(cnt+1)/2+1;
	while(l+1<r){
		ll mid=(l+r)/2;
		FF=mid,FL=mid-1;
		pair<ll,ll> s=find_first(),t=find_last();
		//cout<<mid<<" : "<<endl;
		//erorp(s);
		//erorp(t);
		if(s.F>t.F) l=mid;
		else r=mid;
	}
	FF=l,FL=l-1;
	pair<ll,ll> s=find_first(),t=find_last();
	//cout<<l<<" : "<<endl;
	//erorp(s);
	//erorp(t);
	u=query(1,1,s.S,1,m);
	v=query(1,t.S,m,1,m);
	u=(-u)+s.F*(l+1);
	v=v-t.F*(cnt-(l-1));
	ans=2*(u-v);
	if(l==(cnt+1)/2 && (cnt&1)){
		ans-=Sum(1,s.S-1)-Sum(t.S,m);
	}
	//cout<<"ANS : ";
	cout<<segb[1].S-ans<<endl;
}
void solve(){
	f(i,0,n+q){
		ll v=s[i][1],u=F1[s[i][1]];
		//u=v;
		if(s[i][0]==2) s[i][0]=-1;
		Add_Del(u,v,s[i][0]);
		if(i>n-2){
			calc();
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	read();
	solve();
}
/*
3 6
1 2 3
2 1
1 5
1 6
1 7
2 6
2 2
*/