#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l2[300500],l,r,md;

ll f[300500],p[300500],st[300500][21],st2[300500][21],res;

ll chk(int l,int r){ll k=l2[r-l+1];return min(st[l][k],st[r-(1<<k)+1][k]);}
ll chk2(int l,int r){ll k=l2[r-l+1];return min(st2[l][k],st2[r-(1<<k)+1][k]);}

vector<int> v[300500];
map<ll,ll> mp[2];

int main() {
	l2[0]=-1;
	for(i=1;i<=300500;i++){
		l2[i]=l2[i>>1]+1;
	}
	
	cin.tie(0);
	cin>>t;
	while(t--){
		
		mp[1].clear();
		mp[0].clear();
		
		res=0;
		
		cin>>n;
		for(i=1;i<=n;i++){
			v[i].clear();
			cin>>f[i];
			
			p[i]=f[i]-p[i-1];
			
			//printf("a%d\n",p[i]);
			
			if(i&1){
				st[i][0]=p[i];
				st2[i][0]=1e18;
			}
			else{
				st2[i][0]=p[i];
				st[i][0]=1e18;
			}
		}
		
		for(j=1;j<=19;j++){
			for(i=1;i+(1<<j)-1<=n;i++){
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
				st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
			}
		}
		
		for(i=1;i<=n;i++){
			k=i;
			l=i+1;r=n;
			while(l<=r){
				md=(l+r)/2;
				if(i&1){
					if(chk(i+1,md)+p[i-1]>=0 && chk2(i+1,md)-p[i-1]>=0){
						k=max(k,md);
						l=md+1;
					}
					else r=md-1;
				}
				else{
					if(chk(i+1,md)-p[i-1]>=0 && chk2(i+1,md)+p[i-1]>=0){
						k=max(k,md);
						l=md+1;
					}
					else r=md-1;
				}
			}
			v[k].push_back(i);
		}
		
		for(i=1;i<=n;i++){
			
			mp[i&1][p[i-1]]++;
			
			res+=mp[i&1][-p[i]];
			res+=mp[1-(i&1)][p[i]];
			
			//printf("NMSL %d %d\n",i,res);
			
			
			//mp[1-(i&1)][-p[i]]++;
			
			for(auto j:v[i]){
				//printf("nmsl%d %d\n",j,i);
				
				mp[j&1][p[j-1]]--;
				
			}
		}
		
		cout<<res<<'\n';
	}
}