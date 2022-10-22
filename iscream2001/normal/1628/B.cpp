#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=3e5+10;
const LL INF=1e18;

LL fac[1000005],finv[1000005];

LL C(LL x,LL y){
	if(x<y) return 0;
	return fac[x]*finv[y]%P*finv[x-y]%P;
}

void init(){
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%P;
	finv[1000000]=qpow(fac[1000000],P-2,P);
	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%P;
}
int n,m;
char s[10];
int a[10];
map<int,int> mp;
void MAIN(){
	mp.clear();
	bool flag=0;
	scanf("%d",&n);
	int now;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		if(flag) continue;
		m=strlen(s+1);
		if(m==1){
			flag=1;
			continue;
		}
		if(m==2&&s[1]==s[2]){
			flag=1;
			continue;
		}
		if(m==3&&s[1]==s[3]){
			flag=1;
			continue;
		}
		for(int j=1;j<=m;++j) a[j]=s[j]-'a'+1;
		now=0;
		for(int j=1;j<=m;++j){
			now=now*27+a[j];
		}
		//cout<<"? "<<now<<endl;
		if(mp[now]){
			flag=1;
			continue;
		}
		if(m==2){
			for(int k=0;k<=26;++k){
				now=k;
				for(int j=m;j>=1;--j){
					now=now*27+a[j];
				}
				//cout<<now<<endl;
				mp[now]=1;
			}
		}
		if(m==3){
			now=0;
			for(int j=2;j>=1;--j){
				now=now*27+a[j];
			}
			mp[now]=1;
			now=0;
			for(int j=3;j>=1;--j){
				now=now*27+a[j];
			}
			mp[now]=1;
		}
	}
	if(flag) puts("YES");
	else puts("NO");
	return;
}
/*
*/
int main(){
	//cout<<qpow((LL)16,P-2,P)*(LL)150%P<<endl;
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}