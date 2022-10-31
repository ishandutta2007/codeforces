#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,t,sb[100500],mx[100500],mx2,res;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(mx,0,n*4+50);mx2=0;res=0;
		
		for(i=1;i<=n;i++){
			scanf("%d",&sb[i]);
			mx[sb[i]]++;
			mx2=max(mx2,mx[sb[i]]);
			if(sb[i]==sb[i-1]){res++;}
		}
		
		if(mx2*2>n+1){puts("-1");continue;}
		
		memset(mx,0,n*4+50);mx2=0;
		mx[sb[1]]++;mx[sb[n]]++;mx2=max(mx2,mx[sb[1]]);
		for(i=1;i<=n;i++){
			if(sb[i]==sb[i-1]){mx[sb[i]]+=2;mx2=max(mx2,mx[sb[i]]);}
		}
 
		printf("%d\n",max(mx2-2,res));
	}
}