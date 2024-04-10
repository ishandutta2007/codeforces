#include<bits/stdc++.h>
typedef long long ll;
const int MAXN=600000;
const ll HASH_MOD=1e12+39,P=5;
int N,M;
ll Pow[MAXN+5];
ll h[MAXN+5];
char a[MAXN+5];
bool Find(){
	int l=strlen(a+1);
	ll H=0;
	for(int i=1;i<=l;++i)
		H=(H*P+a[i]-'a'+1)%HASH_MOD;
	for(int i=1;i<=l;++i)
		for(int j='a';j<='c';++j){
			if(j==a[i])
				continue;
			ll x=(H+(j-a[i])*Pow[l-i]%HASH_MOD+HASH_MOD)%HASH_MOD;
			if(*std::lower_bound(h+1,h+N+1,x)==x)
				return 1;
		}
	return 0;
}
int main(){
	Pow[0]=1;
	for(int i=1;i<=MAXN;++i)
		Pow[i]=Pow[i-1]*P%HASH_MOD;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i){
		scanf("%s",a+1);
		int l=strlen(a+1);
		ll H=0;
		for(int j=1;j<=l;++j)
			H=(H*P+a[j]-'a'+1)%HASH_MOD;
		h[i]=H;
	}
	std::sort(h+1,h+N+1);
	for(int i=1;i<=M;++i){
		scanf("%s",a+1);
		if(Find())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}