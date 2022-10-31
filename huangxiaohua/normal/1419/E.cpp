#pragma GCC optimize(2)
#pragma GCC optimize(3)
 
#include<bits/stdc++.h>
using namespace std;
 
long long  i,j,k,kk,t,n,zs[100500],zn,z[100500];
vector<long long > v[100500],zhishu;
bool zz[50000];
map<long long ,bool > used;
 
int main(){
	
	for(i=2;i<=40000;i++){
		if(zz[i]){continue;}
		zhishu.push_back(i);
		for(j=i+i;j<=40000;j+=i){
			zz[j]=1;
		}
		//printf("%d\n",i);
	}
	
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		used.clear();zn=0;
		for(i=0;zhishu[i]<=n;i++){
			if(zhishu[i]==0){break;
			}
			while(n%zhishu[i]==0){
				if(!used[zhishu[i]]){
					used[zhishu[i]]=1;
					zn++;
					zs[zn]=zhishu[i];
					z[zn]=0;
				}
				z[zn]++;
				n/=zhishu[i];
			}
			
		}
		if(n-1){
			zn++;
			zs[zn]=n;z[zn]=1;
		}
		used.clear();
		/*for(i=1;i<=zn;i++){
			printf("z%d %d\n",zs[i],z[i]);
		}*/
		
		if(zn==2&&((z[1]+z[2])==2)){
			printf("%lld %lld %lld\n",zs[1],zs[2],zs[1]*zs[2]);puts("1");continue;
		}
		
		if(zn==1){
			long long res=1;
			for(i=1;i<=z[1];i++){
				res=res*zs[1];
				printf("%lld ",res);
			}puts("\n0");goto aaa;
		}
		
		used[zs[zn]*zs[1]]=1;
		v[zn+1].clear();
		v[zn+1].push_back(1);
		
		for(i=zn;i>=1;i--){
			used[zs[i]*zs[i-1]]=1;
			used[zs[i]]=1;
			v[i].clear();
			
			long long tmp=1;
			for(j=1;j<=z[i];j++){
				tmp=tmp*zs[i];
				v[i].push_back(tmp);
			}
			
			tmp=1;
			for(j=1;j<=z[i];j++){
				tmp=tmp*zs[i];
				for(kk=i+1;kk<=zn;kk++){
					for(k=0;k<v[kk].size();k++){
						v[i].push_back(v[kk][k]*tmp);
					}
				}
			}
		}
		
		/*for(i=1;i<=n+1;i++){
			for(j=0;j<v[i].size();j++){
				printf("%d\n",v[i][j]);
			}
		}*/
		
		for(i=1;i<=zn;i++){
			printf("%lld ",zs[i]);
			for(j=0;j<v[i].size();j++){
				if(used[v[i][j]]){continue;}
				printf("%lld ",v[i][j]);
			}
			if(i!=zn){
				if(i==1&&zn==2){continue;
				}
				printf("%lld ",zs[i]*zs[i+1]);
			}
			else{printf("%lld ",zs[1]*zs[zn]);}
		}
		puts("");
		puts("0");
		aaa:;
	}
}