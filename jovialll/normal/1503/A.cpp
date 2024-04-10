#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define mod 998244353
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int T,n,i,tt,cnt,l;
char s[N],a[N],b[N];
int main(){
	cin>>T;
	while(T--){
		scanf("%d%s",&l,s+1);cnt=0;
		for(i=1;i<=l;++i){
			if(s[i]=='0')++cnt;
		} 
		if((cnt&1)||s[1]!='1'||s[l]!='1')cout<<"NO\n";
		else{
			cnt=0;
			for(i=1;i<=l;++i){
				if(s[i]=='0'){
					++cnt;
					if(cnt&1)a[i]='(',b[i]=')';
					else a[i]=')',b[i]='(';
				}
			}
			tt=(l-cnt)>>1;
			for(i=1;i<=l;++i){
				if(s[i]=='1'){
					if(tt)a[i]=b[i]='(',--tt;
					else a[i]=b[i]=')';
				}
			}cout<<"YES\n";
			for(i=1;i<=l;++i)cout<<a[i];cout<<"\n";
			for(i=1;i<=l;++i)cout<<b[i];cout<<"\n";
		}
	}
	return 0;
}