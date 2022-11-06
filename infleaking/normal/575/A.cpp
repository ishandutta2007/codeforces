#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50100;
struct mat{ll a[2][2];}ept,e;
ll s[N],n,m,mo,k;
mat mul(mat a,mat b){
	mat c=ept;
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	for (int k=0;k<2;k++){
		c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mo;
	}
	return c;
}
mat make(ll s1,ll s2){
	mat c=ept;
	c.a[0][1]=s1;
	c.a[1][0]=1;
	c.a[1][1]=s2;
	return c;	
}
mat make(ll i){
	return make(s[(i+n-1)%n],s[i%n]);
}
int M=1<<16;
mat tr[N*4];
#define x1 (x+x)
#define x2 (x+x+1)
#define Md (l+r>>1)
void build(int x,int l,int r){
	if (l==r)tr[x]=make(l);
	else {
		build(x1,l,Md);
		build(x2,Md+1,r);
		tr[x]=mul(tr[x1],tr[x2]);
	}
}
int pl,pr;
mat query(int x,int l,int r){
	if (pr<l||r<pl||pr<pl)return e;
	if (pl<=l&&r<=pr)return tr[x];
	return mul(query(x1,l,Md),query(x2,Md+1,r));
}
vector<pair<ll,ll> > p;
void trans(ll &f0,ll &f1,mat a){
	ll p0=(f0*a.a[0][0]+f1*a.a[1][0])%mo,p1=(f0*a.a[0][1]+f1*a.a[1][1])%mo;
	f0=p0,f1=p1;
}
mat power(mat a,ll b){
	mat ans=e;
	while (b){
		if (b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}return ans;
}
int main(){
	e.a[0][0]=e.a[1][1]=1;
	cin>>k>>mo>>n;
	if (mo==1){
		cout<<0<<endl;
		return 0;
	}
	for (int i=0;i<n;i++)scanf("%lld",&s[i]);
	ll now=1,f0=0,f1=1;
	cin>>m;
	for (int i=1;i<=m;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		p.push_back(make_pair(x,y));
	}
	sort(p.begin(),p.end());
	while (p.size()&&p.back().first>=k)p.pop_back();
//	p.push_back(make_pair(k,0));
	build(1,0,n-1);
	for (int i=0;i<p.size();i++){
		ll j=p[i].first,v=p[i].second;
		if (i>0&&j==p[i-1].first+1){
			ll f2=(f0*p[i-1].second+f1*v)%mo;
			f0=f1,f1=f2;
			now=j+1;
			if (i==p.size()-1||p[i+1].first>j+1){
				f2=(f0*v+f1*s[(j+1)%n])%mo;
				f0=f1,f1=f2;
				now++;
			}
			continue;
		}
		if (j/n==now/n){
			if (now<j){
				pl=now%n,pr=(j-1)%n;
				trans(f0,f1,query(1,0,n-1));
			}
		}
		else {
			pl=now%n,pr=n-1;
			trans(f0,f1,query(1,0,n-1));
			trans(f0,f1,power(tr[1],(j/n-now/n-1)));
			pl=0,pr=j%n-1;
			trans(f0,f1,query(1,0,n-1));
		}
		now=j+1;
		ll f2=(f0*s[(j-1)%n]+f1*v)%mo;
		f0=f1,f1=f2;
		if (i==p.size()-1||p[i+1].first>j+1){
			f2=(f0*v+f1*s[(j+1)%n])%mo;
			f0=f1,f1=f2;
			now++;
		}
	}
	if (now==k+1)cout<<f0<<endl;
	else if (now==k)cout<<f1<<endl;
	else {
	if (k/n==now/n){
		pl=now%n,pr=(k-1)%n;
		trans(f0,f1,query(1,0,n-1));
	}
	else {
		pl=now%n,pr=n-1;
		trans(f0,f1,query(1,0,n-1));
		trans(f0,f1,power(tr[1],(k/n-now/n-1)));
		pl=0,pr=k%n-1;
		trans(f0,f1,query(1,0,n-1));
	}
	cout<<f1<<endl;
	}
}