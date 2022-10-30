#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n,i,j;
ll sb[4444],k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);memset(sb,0,sizeof(sb));
		for(i=1;i<=n;i++){
			scanf("%lld",&k);if(k<=2048){sb[k]++;}
		}
		for(i=1;i<=1024;i<<=1){sb[i<<1]+=sb[i]>>1;}
		puts((sb[2048])?"yES":"nO");
	}
}