#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[200500],res,sb;
map<int,map<int,int> > mp;
#define chk sb+=a[j];if(sb>=a[i]*2){break;}if(sb==(a[i]^

int main(){
	for(i=1,scanf("%d",&n);i<=n;i++){scanf("%d",&a[i]);}
	for(i=1;i<=n;i++){
		for(j=i+1,sb=0;j<n;j++){chk a[j+1])){res++;mp[i][j+1]=1;}}
		for(j=i-1,sb=0;j>1;j--){chk a[j-1])){res+=1-mp[j-1][i];}}
	}
	printf("%d",res);
}