#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t,a[100500],res;
vector<int> v,qu,qu2;

void ask2(int x){
	for(auto i:qu2){
		printf("B %d\n",i);fflush(stdout);
		scanf("%d",&k);
		ll j=i;
		while(j<=n){
			printf("B %lld\n",j);fflush(stdout);j*=i;
			scanf("%d",&k);
			if(!k){break;}
			x*=i;
		}
	}
	printf("C %d",x);fflush(stdout);
	exit(0);
}

void ask1(){
	for(auto i:qu){
		for(j=i;j<=n;j+=i){if(!a[j]){a[j]=1;res--;}}
		printf("B %d\n",i);fflush(stdout);
		scanf("%d",&k);
	}
	printf("A 1\n");fflush(stdout);
	scanf("%d",&k);
	if(k!=res){
		for(auto i:qu){
			printf("B %d\n",i);fflush(stdout);
			scanf("%d",&k);
			if(k){ask2(i);}
		}
	}
}

int main(){
	scanf("%d",&n);res=n;
	for(i=2;i<=n;i++){
		if(!a[i]){
			v.push_back(i);
			for(j=i;j<=n;j+=i){a[j]=1;}
		}
	}
	memset(a,0,sizeof(a));
	for(auto i:v){
		if(1ll*i*i>n){qu.push_back(i);}
		else{qu2.push_back(i);}
		if(qu.size()==100){
			ask1();qu.clear();
		}
	}
	if(qu.size()>0){
		ask1();qu.clear();
	}
	ask2(1);
}