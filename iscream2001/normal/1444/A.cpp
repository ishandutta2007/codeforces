#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int inf=1e9;
const int N=610;
const LL P=998244353; 

LL p,q;

int main(){
	int T;scanf("%d",&T);
	int t;LL res,pp;
	while(T--){
		LL ans=0;
		scanf("%I64d%I64d",&p,&q);
		if(p%q!=0){
			printf("%I64d\n",p);
			continue;
		}
		//cout<<"y"<<endl;
		for(LL i=2;i<=sqrt(q);++i){
			if(q%i!=0) continue;
			t=0;res=1;
			while(q%i==0){
				q=q/i;
				++t;res=res*i;
			}
			if(p%res==0){
				pp=p;
				while(pp%i==0) pp=pp/i;
				pp=pp*res/i;
				ans=max(ans,pp);
			}
		}
		if(q>1){
			if(p%q==0){
				pp=p;
				while(pp%q==0) pp=pp/q;
				ans=max(ans,pp);
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}