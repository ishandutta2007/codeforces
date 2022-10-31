#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,op,r,a[500500],r1,r2;
vector<tuple<int,int,int,int> >res;

class SB{
	public:
	#define ls ((id<<1))
	#define rs (ls+1)
	#define md ((l+r)>>1)
	int x,y,w,f[2005000],res;
	void ass(int id,int l,int r){
		if(l==r){f[id]=w;return;}
		if(x<=md)ass(ls,l,md);
		else ass(rs,md+1,r);
		f[id]=max(f[ls],f[rs]);
	}
	void que(int id,int l,int r){
		if(x<=l&&r<=y){res=max(res,f[id]);return;}
		if(x<=md)que(ls,l,md);
		if(y>md)que(rs,md+1,r);
	}
	#undef md
}sb;

int get(int l,int rr){
	int res=-1,md=0,r=rr-1;
	while(l<=r){
		md=(l+r)/2;
		sb.x=md;sb.y=rr-1;sb.res=0;
		sb.que(1,1,n);
		if(sb.res>rr)res=max(res,md),l=md+1;
		else r=md-1;
	}
	return res;
}

map<int, vector<int> >mp;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;a[i]=k;
		if(!mp[k].empty()){
			j=mp[k].size()-1;
			sb.x=sb.y=mp[k][j];sb.w=i;
			sb.ass(1,1,n);
			r1=get(1,sb.x);
			r2=(j>=2)?mp[k][j-2]:-1;
			r1=max(r1,r2);
			if(r1>r){
				res.push_back({a[r1],a[i],a[r1],a[i]});
				r=i;
			}
		}
		mp[k].push_back(i);
	}
	cout<<res.size()*4<<endl;
	for(auto [a,b,c,d]:res)cout<<a<<' '<<b<<' '<<c<<' '<<d<<' ';
}