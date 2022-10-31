#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,x,y,it;
ll res,num[66];

struct SB{
	ll x,y;
};
vector<SB> v[35],ans;

vector<SB> add(vector<SB> &v1,vector<SB> &v2){
	vector<SB> tmp=v1;
	int it=tmp.size();
	for(auto [x,y]:v2){
		if(!it){
			tmp.push_back({x,y});
			it++;
		}
		else{
			if(tmp[it-1].x==x){
				tmp[it-1].y+=y;
			}
			else{
				tmp.push_back({x,y});
				it++;
			}
		}
		
		while(it&&tmp[it-1].y>=k){
			tmp[it-1].y%=k;
			if(tmp[it-1].y==0){
				it--;tmp.pop_back();
			}
		}
	}
	return tmp;
}

int main() {
	cin>>n>>k>>m;
	res=1ll*n*m;
	for(i=1;i<=n;i++){
		cin>>x;
		
		if(!it){
			v[0].push_back({x,1});
			it++;
		}
		else{
			if(v[0][it-1].x==x){
				v[0][it-1].y++;
			}
			else{
				v[0].push_back({x,1});
				it++;
			}
		}
		
		while(it&&v[0][it-1].y>=k){
			//printf("NMSL%d\n",it);
			v[0][it-1].y%=k;
			if(v[0][it-1].y==0){
				it--;v[0].pop_back();
			}
		}
	}
	
	for(auto [x,y]:v[0]){
		//cout<<x<<' '<<y<<endl;
		num[0]+=y;
	}
	
	for(i=1;i<=30;i++){
		v[i]=add(v[i-1],v[i-1]);
		
		//cout<<"a"<<i<<endl;
		for(auto [x,y]:v[i]){
			//cout<<x<<' '<<y<<endl;
			num[i]+=y;
		}
		
		if(v[i].size()>1e6){
			cout<<1ll*num[0]*m-1ll*(num[0]+num[0]-num[1])*(m-1);
			return 0;
		}
	}
	
	
	for(i=0;i<=30;i++){
		if((1<<i)&m){
			ans=add(ans,v[i]);
		}
	}
	
	ll r=0;
	for(auto [x,y]:ans){
		r+=y;
	}
	cout<<r;
}