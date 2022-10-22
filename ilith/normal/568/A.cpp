#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int S=2e6,N=S+9;
int q,p,sp[N],sh[N];
vector<int>f;
int isp(int x){
	if(x==1)return 0;
	if(x==2)return 1;
	if(x%2==0)return 0;
	for(rgi i=3;i*i<=x;i+=2){
		if(x%i==0)return 0;
	}
	return 1;
}
int ish(int x){
	f.clear();
	while(x)f.pbk(x%10),x/=10;
	int S=f.size()-1;
	FOR(i,0,S)if(f[i]!=f[S-i])return 0;
	return 1;
}
signed main(){
	FOR(i,1,S){
		sp[i]=sp[i-1]+isp(i),sh[i]=sh[i-1]+ish(i);
	}
	scanf("%d%d",&p,&q);
	int ans=0;
	FOR(i,1,S){
		if(q*sp[i]<=p*sh[i]){
			ans=i;
		}
	}
	if(ans)cout<<ans;
	else puts("Palindromic tree is better than splay tree");
	return 0;
}