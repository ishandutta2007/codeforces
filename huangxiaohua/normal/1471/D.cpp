#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int,int>mp;
int i,j,k,n,t,m,a[300500],pf,tmp,tmp2;
int res1,res2,zs[1050];
vector<int> v,z;
ll kk;
int main(){
	for(i=2;i<=1000;i++){
		if(!zs[i]){
			z.push_back(i);
			for(j=i+i;j<=1000;j+=i){
				zs[j]=1;
			}
		}
	}
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		pf=res2=tmp=tmp2=0;mp.clear();v.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			k=sqrt(a[i]);
			
			if(k*k==a[i]){pf++;continue;}
			
			tmp=1;
			for(j=0;j<z.size();j++){
				if(a[i]%z[j]){continue;}
				tmp2=0;
				while(!(a[i]%z[j])){
					tmp2++;a[i]/=z[j];
				}
				if(tmp2%2){tmp*=z[j];}
			}
			if(a[i]-1){
				tmp*=a[i];
			}
			
			if(!mp[tmp]){
				v.push_back(tmp);
			}mp[tmp]++;
		}
		tmp=tmp2=0;
		for(i=0;i<v.size();i++){
			//printf("%d %d\n",v[i],mp[v[i]]);
			
			tmp=max(tmp,mp[v[i]]);
			if(!(mp[v[i]]%2)){
				res2+=mp[v[i]];
			}
			else{
				tmp2=max(tmp2,mp[v[i]]);
			}
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			scanf("%lld",&kk);
			if(!kk){printf("%d\n",max(pf,tmp));}
			else{printf("%d\n",max(pf+res2,tmp2));}
		}
	}
}