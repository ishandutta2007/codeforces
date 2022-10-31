#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,res;
vector<pair<int,int> >v;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		v.clear();res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			v.push_back({k,i});
		}
		sort(v.begin(),v.end());
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				auto [l,r]=v[i];
				auto [l1,r1]=v[j];
				if(1ll*l*l1>1ll*n*2){break;}
				if(l*l1==r+r1){res++;}
			}
		}
		printf("%d\n",res);
	}
}