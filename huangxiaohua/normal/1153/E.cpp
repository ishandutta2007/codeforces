#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,vx[6666],vy[6666],l,r,md,res;
vector<pair<int,int> >v;

int main() {
	cin.tie(0);
	cin>>n;
	
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<int>lim(1,n);
	
	while(v.size()!=2){
		k=lim(rng);
		l=1;r=n;res=0;
		if(rng()&1){
			if(vx[k])continue;
			cout<<"? "<<k<<' '<<1<<' '<<k<<' '<<n<<endl;
			vx[k]=1;
			cin>>j;
			if(j&1){
				while(l<=r){
					md=(l+r)/2;
					cout<<"? "<<k<<' '<<1<<' '<<k<<' '<<md<<endl;
					cin>>j;
					if(j&1)r=md-1;
					else res=max(res,md),l=md+1;
				}
				vy[++res]=1;
				v.push_back({k,res});
			}
		}
		else{
			if(vy[k])continue;
			vy[k]=1;
			cout<<"? "<<1<<' '<<k<<' '<<n<<' '<<k<<endl;
			cin>>j;
			if(j&1){
				while(l<=r){
					md=(l+r)/2;
					cout<<"? "<<1<<' '<<k<<' '<<md<<' '<<k<<endl;
					cin>>j;
					if(j&1)r=md-1;
					else res=max(res,md),l=md+1;
				}
				vx[++res]=1;
				v.push_back({res,k});
			}
		}
	}
	cout<<"! ";
	for(auto [i,j]:v)cout<<i<<' '<<j<<' ';
}