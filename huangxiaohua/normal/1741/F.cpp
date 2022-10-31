#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[1000500],NMSL[1000500],NMSL1[1005000],NMSL2[1005000],NMSL3[1005000],it;

struct SB{
	int f[1000500],n;
	void init(int x){
		n=x;memset(f,0,n*4+50);
	}
	void addl(int x,int y){
		for(;x<=n;x+=(-x&x)){f[x]+=y;}
	}
	int getl(int x,int y=0){
		for(;x;x-=(-x&x)){y+=f[x];}return y;
	}
	void addr(int x,int y){
		for(;x;x-=(-x&x)){f[x]+=y;}
	}
	int getr(int x,int y=0){
		for(;x<=n;x+=(-x&x)){y+=f[x];}return y;
	}
}fl,fr;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		map<int,vector<tuple<int,int,int,int,int> > >mp;
		multiset<int> s;
		it=0;
		for(i=1;i<=n;i++){
			int l,r,cl;
			cin>>l>>r>>cl;
			s.insert(l); s.insert(r);
			NMSL1[i]=l; NMSL2[i]=r; NMSL3[i]=cl;
			NMSL[++it]=l; NMSL[++it]=r;
		}
		sort(NMSL+1,NMSL+it+1);
		m=unique(NMSL+1,NMSL+it+1)-NMSL-1;
		fl.init(m); fr.init(m);
		for(i=1;i<=n;i++){
			int l,r;
			l=lower_bound(NMSL+1,NMSL+m+1,NMSL1[i])-NMSL;
			r=lower_bound(NMSL+1,NMSL+m+1,NMSL2[i])-NMSL;
			fl.addl(r,1); fr.addr(l,1);
			mp[NMSL3[i]].push_back({NMSL1[i],NMSL2[i],l,r,i});
		}
		
		for(auto [cl,v]:mp){
			for(auto [l,r,l1,r1,id]:v){
				s.erase(s.find(l)); s.erase(s.find(r));
				fl.addl(r1,-1); fr.addr(l1,-1);
			}
			for(auto [l,r,l1,r1,id]:v){
				res[id]=1e9;
				if(fl.getl(l1)+fr.getr(r1)!=(s.size()/2)){
					res[id]=0;continue;
				}
				auto it=s.lower_bound(r);
				if(it!=s.end()){
					auto x=*it;
					res[id]=min(res[id],x-r);
				}
				if(it!=s.begin()){
					it--;
					auto x=*it;
					res[id]=min(res[id],l-x);
				}
			}
			for(auto [l,r,l1,r1,id]:v){
				s.insert(l); s.insert(r);
				fl.addl(r1,1); fr.addr(l1,1);
			}
		}
		for(i=1;i<=n;i++)cout<<res[i]<<' ';
		cout<<'\n';
	}
}