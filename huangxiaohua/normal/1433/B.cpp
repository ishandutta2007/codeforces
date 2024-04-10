#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t,a[500],tmp,res,sbn,one,sb;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);sbn=sb=one=res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			one+=a[i];
		}
		sb=0;
		for(i=1;i<=n;i++){
			if(a[i]==0){res+=sb;}
			else {sb=1;sbn++;}
			if(one==sbn){break;
			}
		}
		printf("%d\n",res);
	}
}