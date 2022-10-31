#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int t,n,i,sb[100500],res,a,num[100500],numn,k;
 
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
		res=0;k=-1;
    	memset(sb,0,sizeof(sb));
    	memset(num,0,sizeof(num));
    	for(i=1;i<=n;i++){
    		scanf("%d",&a);
    		if(sb[a]==0){numn++;num[numn]=a;}
    		sb[a]++;
    		res=max(res,sb[a]);
		}
		for(i=1;i<=numn;i++){
			if(sb[num[i]]==res){k++;}
		}
    	printf("%d\n",(n-res-k)/(res-1));
	}
}