#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#include<bitset>
#include<vector>
#define LL long long
using namespace std;
const LL inf=1e18;
const int N=3e5+10;
bool not_pri[200];
int pri[200];
LL mu[200],mx[200];
LL P(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x;
		y>>=1;x=x*x;
	}
	return re;
}
LL get(LL n,LL x){
	LL l=1,r=mx[x],mid;
	while(l!=r){
		mid=l+r+1>>1;
		if(P(mid,x)<=n) l=mid;
		else r=mid-1;
	}
	return l-1;
}
int main(){
	mu[1]=1;
	for(int i=2;i<=100;++i){
		if(!not_pri[i]){
			pri[++pri[0]]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=pri[0]&&pri[j]*i<=100;++j){
			not_pri[pri[j]*i]=1;
			if(i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			}
			else mu[pri[j]*i]=-mu[i];
		}
	}
	mx[2]=1000000000;
	mx[3]=1000000;
	for(LL i=4;i<=68;++i){
		LL j=1;
		while(pow(j+1,i)<=inf){
			++j;
			//cout<<j<<endl;
		}
		mx[i]=j;
		//cout<<i<<" "<<mx[i]<<endl;
	}
	int T;scanf("%d",&T);
	LL n,ans;
	while(T--){
		scanf("%I64d",&n);
		ans=n-1;
		for(LL i=2;i<=68;++i)
			ans+=mu[i]*get(n,i);
		printf("%I64d\n",ans);
	}
	return 0;
}