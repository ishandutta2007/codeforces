#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define x0 nmsl1
#define y0 nmsl2
#define NIMASILE if(x==n){d1=-1;}if(x==1){d1=1;}if(y==m){d2=-1;}if(y==1){d2=1;}

int i,j,k,t,d1,d2,lst,cur;
ll n,m,x,y,x0,y0,res,p,t1,t2,p0,r0;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
vector<ll> v;
map<pair<int,int>,bool> mp;

int walk(int sn){
	NIMASILE;
	if(sn){
		cur++;NIMASILE;
		x+=d1;y+=d2;NIMASILE;
	}
	NIMASILE;
	while(x!=x0&&y!=y0){
		cur++;NIMASILE;
		x+=d1;y+=d2;NIMASILE;
	}
	NIMASILE;
	int res=cur-lst;lst=cur;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>x>>y>>x0>>y0>>p;
		p0=p*ksm(100,M-2)%M;
		p=(M+1-p*ksm(100,M-2)%M)%M;
		d1=d2=1;
		lst=0;cur=0;
		
		v.clear();
		mp.clear();
		r0=walk(0);res=0;
		
		while(!mp.count({x*d1,y*d2})){
			mp[{x*d1,y*d2}]=1;
			v.push_back(walk(1));
		}
		
		k=v.size();
		j=1;
		for(auto i:v){
			t1=ksm(M+1-p,M-2)*ksm(p,j)%M;
			t2=ksm(M+1-ksm(p,k),M-2);
			res+=i*t1%M*t2%M;
			j++;
		}
		res%=M;
		res=(res*p0+r0)%M;
		cout<<res<<'\n';
		
	}
}