#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,mod;
inline int add(int a,int b,const int mod=mod){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b,const int mod=mod){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b,const int mod=mod){return (ll)a*b%mod;}
inline int qpow(int a,int b,const int mod=mod){int ret=1;for(;b;b>>=1,a=mul(a,a,mod))if(b&1)ret=mul(ret,a,mod);return ret;}
inline int inv(int x,const int mod=mod){
	return qpow(x,mod-2,mod);
}
/* math */
map<int,int> cnt;
int inv2,inv4;
inline void div(int l,int r,int h){
	if(l==r||h==1){cnt[r-l+1]++; return ;}
	int mid=(l+r)>>1;
	div(l,mid,h-1);
	div(mid+1,r,h-1);
}
int invS[1000010];
inline void init(int n){
	for(int i=2;i<=n;i++)invS[i] = add(invS[i-1], mul(i-2, inv(i)));
}

int solve(int Len1,int Len2){
	int ret=0;
	for(int i=1;i<=Len1;i++){
		ret = add(ret, sub(invS[i+Len2],invS[i]));
//		if(Len1!=Len2)cout<<ret<<endl;
	}return mul(ret,inv2);
}
int ans = 0;

int main()
{
	cin >> n >> k >> mod;
	init(n*2);
	inv2=qpow(2,mod-2),inv4=qpow(4,mod-2);
	div(1,n,k);
	map<int,int>::iterator itt,itt2;
	for(itt=cnt.begin();itt!=cnt.end();itt++){
//		cout<<itt->first<<" "<<itt->second<<endl;
		ans = add(ans, mul(solve(itt->first,itt->first), mul(inv2, mul(itt->second,itt->second-1))));
		ans = add(ans, mul(itt->second, mul(inv4,mul(itt->first,itt->first-1))));
	}
	for(itt=cnt.begin();itt!=cnt.end();itt++)
		for(itt2=itt;itt2!=cnt.end();itt2++)if(itt != itt2){
			ans = add(ans, mul(solve(itt->first,itt2->first), mul(itt->second,itt2->second)));
		}
	cout << ans << endl;
}