#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[5050],a[5050],mp[5050];
int sb,mx,res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,-0x3f,sizeof(f));
		f[0]=0;res=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		for(i=1;i<=n;i++){
			if(a[i]==a[i-1]||i==1)f[i]=f[i-1]+1;
			sb=0,mx=0;
			for(j=1;j<=n;j++)mp[j]=0;
			for(j=i-1;j>=1;j--){
				sb++;
				mx=max(mx,++mp[a[j]]);
				if(!(sb&1)&&mx+mx<=sb){
					if(j==1||a[j-1]==a[i]){
						f[i]=max(f[i],f[j-1]+1);
					}
				}
			}
		}
		
		sb=0,mx=0;
		res=max(res,f[n]);
		unordered_map<int,int> mp;
		for(j=n;j>=1;j--){
			sb++;
			mx=max(mx,++mp[a[j]]);
			if(!(sb&1)&&mx+mx<=sb){
				res=max(res,f[j-1]);
			}
		}
		cout<<res<<'\n';
	}
}