#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const ll mod=998244353;
const int maxn=2000010;
ll getax(ll a,ll x){
	ll t1=1,t2=a,t3=1;
	while (x!=0){
		if (x%(t1*2)/t1==1){
			t3=t3*t2%mod;
			x=x-t1;
		}
		t1=t1*2; t2=t2*t2%mod;
	}
	return t3;
}

ll n,m,k;
ll a[maxn];

int check(ll n,ll m){
	ll tot=0,t1=0;
	for (int i=1;i<=k;i++){
		if (a[i]/n>=2) tot=tot+(a[i]/n);
		if (a[i]/n>=3) t1=1;
	}
	if (m%2==0){
		if (tot>=m) return 1;
	}
	else{
		if (tot>=m){
			if (t1==0) return 0;
			else return 1;
		}
	}
	return 0;
}

void solve(){
	n=read(); m=read(); k=read();
	for (int i=1;i<=k;i++) a[i]=read();
	if (check(n,m)||check(m,n)) printf("Yes\n");
	else printf("No\n");
}

int main(){

	int T,opt;
	T=read();
	for (opt=1;opt<=T;opt++){
		solve();
	}

	return 0;
}