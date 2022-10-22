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

const int maxn=2000010;
ll n,m;
ll x[maxn],p[maxn],c[maxn],mx[maxn];
map <ll,ll> mp,tot,ans;
map <ll,ll>::iterator iter;
ll t1,t2,las,fla;
void solve(){
	n=read(); m=read();
	mp.clear();
	tot.clear();
	ans.clear();
	fla=0;
	for (int i=1;i<=n;i++){
		x[i]=read(); p[i]=read(); ans[i]=1;
		mp[x[i]]=0;
		tot[x[i]]=0;
		ans[x[i]]=0;
	}
	for (int i=1;i<=n;i++){
		mp[x[i]-p[i]+1]+=1;
		mp[x[i]+1]-=2;
		mp[x[i]+p[i]+1]+=1;
	}
	t1=0; t2=0; las=-1e9-10;
	for(iter = mp.begin(); iter != mp.end(); iter++){
    	t2+=t1*(iter->first-las)+iter->second;
    	t1+=iter->second;
    	tot[iter->first]=t2;
    	las=iter->first;
    }
    for(iter = tot.begin(); iter != tot.end(); iter++){
    	t1=iter->first;
    	t2=iter->second;
    	if (t2>m){
			fla++; c[fla]=t1;
		}
    }
    if (fla==0){
		for (int i=1;i<=n;i++) printf("1"); 
		printf("\n");
		return;
	}
	for (int i=1;i<=n;i++){
		fla++; c[fla]=x[i];
	}
	sort(c+1,c+fla+1);
	t1=-1e18;
	t1=t1*5; las=-1e9-10; las=las*3;
	for (int i=1;i<=fla;i++){
		if ((tot[c[i]]-m<=0)&&(t1==-1e18*5)) continue;
		t1=max(t1+(c[i]-las),tot[c[i]]-m);
		las=c[i];
		ans[c[i]]=max(ans[c[i]],t1);
	}
	t1=-1e18; t1=t1*5; las=1e9+10; las=las*3;
	for (int i=fla;i>=1;i--){
		if ((tot[c[i]]-m<=0)&&(t1==-1e18*5)) continue;
		t1=max(t1+(las-c[i]),tot[c[i]]-m);
		las=c[i];
		ans[c[i]]=max(ans[c[i]],t1);
	}
	for (int i=1;i<=n;i++){
		if (ans[x[i]]<=p[i]) printf("1");
		else printf("0");
	}
	printf("\n");
}

int main(){

	int T,opt;
	T=read();
	for (opt=1;opt<=T;opt++){
		solve();
	}

	return 0;
}
/*
2
6 12
4 5
1 6
12 5
5 5
9 7
8 3

5 1
1 2
2 1
3 1
4 1
5 1 

*/