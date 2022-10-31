#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<math.h>
#define LL unsigned long long int
using namespace std;
LL i,j,n,m,k,mx,mn,l,no,tmp;
 
int main(){
	
	scanf("%llu",&n);
	for(i=1;i<=n;i++){
		scanf("%llu%llu",&m,&k);no=0;
		for(j=1;j<=k-1;j++){
			mx=0;mn=99;tmp=m;
			for(l=1;l<=(LL)log10(m)+1;l++){
				mx=max(tmp%10,mx);
				mn=min(tmp%10,mn);
				if(tmp%10==0){no=1;break;}
				tmp/=10;
			}
			m+=mx*mn;//printf("%llu %llu %llu \n",mx,mn,m);
			if(no==1){break;
			}
		}
		printf("%llu\n",m);
	}
 
	return 0;
}