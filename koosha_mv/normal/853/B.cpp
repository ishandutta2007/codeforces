#include <bits/stdc++.h>
#define nmax 100005
 
using namespace std;
 
typedef long long ll;
 
struct node{
	int d,f,t,c;
};
 
ll dp[nmax*10];
ll pas[nmax];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m,k;
	cin >> n >> m >> k;
	
	vector<node> flights(m);
	for(int i=0;i<m;i++){
		cin >> flights[i].d >> flights[i].f >> flights[i].t >> flights[i].c;
	}
	
	sort(flights.begin(),flights.end(),[](node &p,node &q){
		return p.d<q.d;
	});
	
	fill(pas+1,pas+n+1,1e13);
	ll cur=1ll*n*ll(1e13);
	int ind=m-1;
	for(int i=1e6;i>=1;i--){
		while( ind>=0 && flights[ind].d>=i){
			if(!flights[ind].f){
				cur-=pas[flights[ind].t];
				pas[flights[ind].t]=min(pas[flights[ind].t],ll(flights[ind].c));
				cur+=pas[flights[ind].t];
			}
			ind--;
		}
		dp[i]=cur;
	}
	
	fill(pas+1,pas+n+1,1e13);
	cur=1ll*n*ll(1e13);
	ind=0;
	ll ans=2e18;
	
	for(int i=1;i<=int(1e6);i++){
		while(ind<m && flights[ind].d<=i){
			if(!flights[ind].t){
				cur-=pas[flights[ind].f];
				pas[flights[ind].f]=min(pas[flights[ind].f],ll(flights[ind].c));
				cur+=pas[flights[ind].f];
			}
			ind++;
		}
		if(i+k+1<=1e6){
			ans=min(ans,cur+dp[i+k+1]);
		}
	}
	
	if(ans<=1e13){
		cout << ans << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
}