#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],res,b[200500],it;

int main(){
	scanf("%d",&t);a[0]=-1;
	while(t--){
		scanf("%d",&n);
		it=0;res=0;
		for(i=1;i<=n;i++){
			scanf("%1d",&a[i]);
			if(a[i]==a[i-1]){
				b[it]++;
			}
			else{
				b[++it]=1;
			}
		}
		for(i=1,j=1;i<=it;i++){
			res++;
			for(j=max(j,i);j<=it;j++){
				if(b[j]>1){break;}
			}
			if(j<=it){
				b[j]--;
			}
			else{
				i++;
			}
		}
		printf("%d\n",res);
	}
}