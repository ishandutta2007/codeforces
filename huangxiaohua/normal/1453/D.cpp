#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,m;
ll n;

vector<int> v;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(n%2){puts("-1");continue;}
		
		i=-1;
		n/=2;
		k=0;
		v.clear();
		if(n&1){n--;v.push_back(1);}
		
		while(n){
			if(n&1){
				v.push_back(1);k++;
				for(j=1;j<=i;j++){
					v.push_back(0);
				}
			}
			n>>=1;i++;
		}
		m=v.size()-1;
		
		printf("%d\n",m+k+1);
		
		for(i=0;i<=m;i++){
			printf("%d ",v[i]);
		}
		for(i=1;i<=k;i++){
			printf("1 ");
		}puts("");
	}
}