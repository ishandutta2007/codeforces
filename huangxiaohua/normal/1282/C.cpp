#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,f[200500];
ll n,m,x,y,a,b,n0,n1,s0,s1,tmp,sum,t0,t1,res;

set<int> s;
map<int,int> mp0,mp1;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>x>>y;
		s.clear();mp0.clear();mp1.clear();
		
		res=n0=n1=s0=s1=sum=0;
		
		for(i=1;i<=n;i++){
			cin>>f[i];
			if(f[i])n1++;
			else n0++;
		}
		for(i=1;i<=n;i++){
			cin>>k;
			s.insert(k);
			if(f[i])mp1[k]++;
			else mp0[k]++;
		}
		
		s.insert(m+1);
		
		for(auto i:s){
			if((i-1)>=sum){
				t0=min(n0,(i-1-sum)/x);
				t1=min(n1,(i-1-sum-t0*x)/y);
				res=max(res,t0+t1+s0+s1);
			}
			ll xx=mp0[i],yy=mp1[i];
			s0+=xx;s1+=yy;
			n0-=xx;n1-=yy;
			sum+=xx*x+yy*y;
		}
		
		cout<<res<<'\n';
	}
}