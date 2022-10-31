#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t,a[50500],nxt[50500];
ll res;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			nxt[i]=i+1;
		}
		for(i=1;i<=n;i++){
			res+=a[i]-1;
			if(a[i]>=5000){a[i]=5000;}
			while(a[i]>1){
				for(j=i+a[i];j<=n;j=k){
					if(a[j]==1){k=nxt[j];continue;}
					k=j+a[j];a[j]--;
					if(a[j]<1){a[j]=1;}
				}
				a[i]--;
			}
			k=0;
			for(j=n;j>=1;j--){
				if(a[j]!=1){k=0;}
				else{
					if(!k){k=j+1;}
					else{nxt[j]=k;}
				}
			}
		}
		printf("%lld\n",res);
	}
}