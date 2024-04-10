#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000],sb;
vector<int> v1,v2;

int main(){
	cin>>n>>m;
	for(t=1;;t++){
		if(k+t>n+m)break;
		k+=t;
	}
	t--;
	for(i=t;i>=1;i--){
		if(n>=i){
			n-=i;a[i]=1;
			v1.push_back(i);
		}
	}
	for(i=1;i<=t;i++){
		if(!a[i]){
			v2.push_back(i);
		}
	}
	printf("%d\n",v1.size());
	for(auto i:v1)printf("%d ",i);
	puts("");
	printf("%d\n",v2.size());
	for(auto i:v2)printf("%d ",i);
	puts("");
}