#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500],res,res2,sl,sr,l,r;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&l,&r);
		memset(a,0,n*4+50);
		memset(b,0,n*4+50);
		for(i=1;i<=l;i++){
			scanf("%d",&k);
			a[k]++;
		}
		for(i=1;i<=r;i++){
			scanf("%d",&k);
			b[k]++;
		}
		res=res2=0;
		sl=sr=0;
		for(i=1;i<=n;i++){
			k=min(a[i],b[i]);
			a[i]-=k;b[i]-=k;
			sl+=a[i];
			sr+=b[i];
		}
		for(i=1;i<=n;i++){
			if(sl>sr){
				k=min(sl-sr,a[i]-(a[i]&1));
				res+=k/2;
				sl-=k;a[i]-=k;
			}
			else{
				k=min(sr-sl,b[i]-(b[i]&1));
				res+=k/2;
				sr-=k;b[i]-=k;
			}
		}
		res+=max(sl,sr);
		printf("%d\n",res);
	}
}