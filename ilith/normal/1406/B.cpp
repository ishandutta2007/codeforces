#include<bits/stdc++.h>
using namespace std;
long long t,n,u;
long long ff,zz; 
long long f[100010];
long long z[100010];
long long ans;
int main(){
	cin>>t;
	while(t--){
		ans=-1;
		ff=zz=0;
		ans*=1000000ll;
		ans*=1000000ll;
		ans*=1000000ll;
		cin>>n;
		while(n--){
			cin>>u;
			if(u>=0){
				z[++zz]=u;
			}
			else{
				f[++ff]=-u;
			}
		}
		sort(f+1,f+ff+1);
		sort(z+1,z+zz+1);
		if(!zz){
			ans=1;
			for(long long i=1;i<=5;i++){
				ans*=-f[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		for(long long i=0;i<=5;i++){
			if(ff>=i&&zz>=5-i){
				long long res=1;
				for(long long j=0;j<i;j++){
					res*=-f[ff-j];
				}
				for(long long j=0;j<5-i;j++){
					res*=z[zz-j];
				}
				if(res>ans){
					ans=res;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}