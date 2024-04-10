#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define b(x) (1ull<<((x)-1))

int i,j,k,n,m,t,id[10050],it;
ll f[15],res;
vector<int> v;

int main(){
	for(i=1;i<(1<<13);i++){
		if(__builtin_popcount(i)==6){id[++it]=i;}
	}
    scanf("%d",&n);
	for(i=1;i<=13;i++){
		v.clear();
		for(j=1;j<=n;j++){
			if(id[j]&b(i)){v.push_back(j);}
		}
		if(v.empty())continue;
		printf("? %d ",v.size());for(auto j:v){printf("%d ",j);}cout<<endl;scanf("%llu",&f[i]);
	}
	puts("! ");
	for(i=1;i<=n;i++){
		res=0;
		for(j=1;j<=13;j++){
			if(b(j)&id[i]){continue;}
			res|=f[j];
		}
		printf("%llu ",res);
	}
}