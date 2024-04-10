#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,k;
ll n,m,res;

int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			k=(i^j);
			if(!k){
				continue;
			}
			if(k>n){
				continue;
			}
			if(k+i<=j||k+j<=i||i+j<=k){
				continue;
			}
			//printf("%d %d %d\n",i,j,k);
			res++;
		}
	}
	cout<<res/6;
}