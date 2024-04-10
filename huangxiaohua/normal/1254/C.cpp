#include <bits/stdc++.h>
using namespace std;

long long i,j,k,t,n,m,it,m1,m2;
long long sb,l[3050],r[3050];

vector<pair<long long,long long> >v;

signed main(){
	scanf("%lld",&n);
	k=2;
	for(i=3;i<=n;i++){
		printf("2 1 %lld %lld\n",k,i);
		fflush(stdout);
		scanf("%lld",&j);
		if(j<0){k=i;}
	}
	for(i=2;i<=n;i++){
		if(i==k){continue;}
		printf("1 1 %lld %lld\n",k,i);
		fflush(stdout);
		scanf("%lld",&j);
		v.push_back({-j,i});
	}
	sort(v.begin(),v.end());
	for(auto [i,j]:v){
		if(!it){it=j;continue;}
		printf("2 1 %lld %lld\n",it,j);
		fflush(stdout);
		scanf("%lld",&sb);
		if(sb>=1){
			r[++m2]=j;
		}
		else{
			l[++m1]=j;
		}
	}
	printf("0 1 %lld ",k);
	for(i=m1;i>=1;i--){
		printf("%lld ",l[i]);
	}
	printf("%lld ",it);
	for(i=1;i<=m2;i++){
		printf("%lld ",r[i]);
	}
	fflush(stdout);
}