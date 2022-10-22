#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const LL P=998244353;
LL gcd(LL a,LL b) {
    return b?gcd(b,a%b):a;
}
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
int n;
char s[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		int ans=0;
		for(int i=1;i<=n;++i){
			if(i>1&&s[i-1]==s[i]&&s[i]!='.'){
				s[i]='.';
				++ans;
			}
			if(i>2&&s[i-2]==s[i]&&s[i]!='.'){
				s[i]='.';
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}