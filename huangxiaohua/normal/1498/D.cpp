#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,sb,ans[100500]={1},x,y,it;
ll tmp;

int main(){
	scanf("%lld%lld",&t,&m);
	while(t--){
		it++;
		scanf("%lld%lld%lld",&k,&x,&y);
		if(k==1){
			x=(x+99999ll)/100000;
			for(i=m;i>=0;i--){
				if(ans[i]){
					tmp=i;
					for(j=1;j<=y;j++){
						tmp+=x;
						if(tmp>m||ans[tmp]){break;}
						ans[tmp]=it;
					}
				}
			}
		}
		else{
			for(i=m;i>=1;i--){
				if(ans[i]){
					tmp=i;
					for(j=1;j<=y;j++){
						if((tmp*x+99999)/100000==tmp){break;}
						tmp=(tmp*x+99999)/100000;
						if(tmp>m||ans[tmp]){break;}
						if(!ans[tmp]){ans[tmp]=it;}
					}
				}
			}
		}
	}
	for(i=1;i<=m;i++){
		printf("%lld ",(ans[i])?ans[i]:-1);
	}
}