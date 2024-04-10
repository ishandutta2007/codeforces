#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=1e6+10;

void init(){
}

int n,m;
LL a[1005];
LL b[1005];
map<LL,LL> mp;
int pos[1005];
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		a[i]=a[i]*(LL)10000+(LL)i;
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;++i){
		mp[b[i]]=i;
	}
	for(int i=1;i<=n;++i){
		a[i]=mp[a[i]];
		pos[a[i]]=i;
	}
	int ans=0;
	for(int i=n;i>=1;--i){
		for(int j=a[i]+1;j<=n;++j){
			if(pos[j]<i)
			++ans;
		}
	}
	printf("%d\n",ans);
	for(int i=n;i>=1;--i){
		for(int j=a[i]+1;j<=n;++j){
			if(pos[j]<i) printf("%d %d\n",pos[j],i);
		}
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}