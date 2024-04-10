#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize(2)

int i,j,k,n,m,p[105000],pn,l,mn,k1,k2,res=11451419,t;
bool used[1200000];
ll a[200500],tmp;
unordered_set<ll> s[2];
unordered_map<int,ll> mp2;
void init(){
	srand(time(0));
	for(i=2;i<=1100000;i++){
		if(!used[i]){used[i]=1;p[++pn]=i;}
		for(j=1;j<=pn;j++){
			if(1ll*i*p[j]>1100000){break;}
			used[i*p[j]]=1;
			if(!(i%p[j])){break;}
		}
	}
	for(int T=1;T<=30;T++){
		k=p[T];k1=0;
		for(i=1;i<=n;i++){
			j=p[T];
			if(a[i]>=j){k1+=min(j-a[i]%j,a[i]%j);}
			else{k1+=j-a[i];}
		}
		res=min(res,k1);
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	init();
	l=max(-1ll*res,2-a[1]);
	for(i=l;i<=res;i++){
		mp2[i]=a[1]+i;
	}
	for(i=1;i<=pn;i++){
		j=l+p[i]-mp2[l]%p[i];
		if(abs(j)>res){
			continue;
		}
		s[1].insert(p[i]);mn=11451419;
		for(;j<=res;j+=p[i]){
			mn=min(mn,abs(j));
			while(!(mp2[j]%p[i])){mp2[j]/=p[i];}
		}
	}
	for(i=l;i<=res;i++){
		if(mp2[i]-1){
			s[1].insert(mp2[i]);
		}
	}
	for(auto i:s[1]){
		k1=0;
		for(j=1;j<=n;j++){
			if(a[j]>=i){k1+=min(i-a[j]%i,a[j]%i);}
			else{k1+=i-a[j];}
			if(k1>=res){k1=11451419;break;}
		}
		res=min(res,k1);
	}
	printf("%d\n",res);
}