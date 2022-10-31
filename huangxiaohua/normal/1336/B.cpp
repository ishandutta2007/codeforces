#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,l,n1,n2,n3,t;
set<ll> s1,s2,s3;
ll res;
ll cal(ll x,ll y,ll z){
	return (x-y)*(x-y)+(x-z)*(x-z)+(z-y)*(z-y);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n1,&n2,&n3);
		s1.clear();s2.clear();s3.clear();
		res=5e18;
		s1.insert(-1);s1.insert(1145141919);
		for(i=1;i<=n1;i++){
			scanf("%d",&k);s1.insert(k);
		}
		
		s2.insert(-1);s2.insert(1145141919);
		for(i=1;i<=n2;i++){
			scanf("%d",&k);s2.insert(k);
		}
		
		s3.insert(-1);s3.insert(1145141919);
		for(i=1;i<=n3;i++){
			scanf("%d",&k);s3.insert(k);
		}
		
		for(auto i:s1){
			if(i==-1||i==1145141919){continue;}
			
			auto it=s2.lower_bound(i);
			auto it2=s3.lower_bound((i+*it+1)/2);
			
			if(*it==-1||*it==1145141919){goto aaaa;}
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			it2--;
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			
			aaaa:;
			it=s3.lower_bound(i);
			it2=s2.lower_bound((i+*it+1)/2);
			
			if(*it==-1||*it==1145141919){continue;}
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			it2--;
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
		}
		
		for(auto i:s2){
			if(i==-1||i==1145141919){continue;}
			
			auto it=s1.lower_bound(i);
			auto it2=s3.lower_bound((i+*it+1)/2);
			
			if(*it==-1||*it==1145141919){goto aaaaa;}
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			it2--;
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			
			aaaaa:;
			it=s3.lower_bound(i);
			it2=s1.lower_bound((i+*it+1)/2);
			
			if(*it==-1||*it==1145141919){continue;}
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			it2--;
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
		}
		
		for(auto i:s3){
			if(i==-1||i==1145141919){continue;}
			
			auto it=s1.lower_bound(i);
			auto it2=s2.lower_bound((i+*it+1)/2);
			
			if(*it==-1||*it==1145141919){goto aaa;}
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			it2--;
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			
			aaa:;
			it=s2.lower_bound(i);
			it2=s1.lower_bound((i+*it+1)/2);
			
			if(*it==-1||*it==1145141919){continue;}
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
			it2--;
			if(*it2!=-1&&*it2!=1145141919){
				res=min(cal(*it,*it2,i),res);
			}
		}
		
		printf("%lld\n",res);
	}
}