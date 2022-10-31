// Hydro submission #62dfdb1d25d42d0516212e81@1658837790445
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5, mod=1e9+7;
int n, m, cnt, ans=1, p[N], pr[N], rec[N];
map<int,int> mp[N];
multiset<int> st[N];
int read() {
	int a=0, f=1; char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) a=a*10+c-'0', c=getchar();
	return a*f;
}
void ora() {
	for(int i=2;i<=2e5;++i) {
		if(!p[i]) p[i]=i, pr[++cnt]=i;
		for(int j=1;j<=cnt&&i*pr[j]<=2e5;++j) {
			p[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
}
int fp(int x,int y) {
	x%=mod;	int z=1;
	for(;y;x=x*x%mod,y>>=1) if(y&1) z=z*x%mod;
	return z;
}
int getinv(int x) { return fp(x,mod-2); }
void solve(int x,int y) {
	vector<pair<int,int> > t;
	#define fr first
	#define sc second
	while(y>1) {
		int a=0, d=p[y];
		while(y%d==0) y/=d, ++a;
		t.push_back({d,a});
	}
	for(auto tt:t) {
		int _p=tt.fr, _a=tt.sc;
		if(mp[x][_p]==0) {
			++rec[_p], st[_p].insert(_a);
			if(rec[_p]==n) {
				(ans*=fp(_p,*st[_p].begin()))%=mod;
			}
			mp[x][_p]=_a;
		} else {
			if(rec[_p]==n) {
				int inv=getinv(fp(_p,*st[_p].begin()));
				(ans*=inv)%=mod;
			}
			st[_p].erase(st[_p].find(mp[x][_p]));
			mp[x][_p]+=_a;
			st[_p].insert(mp[x][_p]);
			if(rec[_p]==n) {
				(ans*=fp(_p,*st[_p].begin()))%=mod;
			}
		}
	}
}
signed main() {
	ora();
	n=read(), m=read();
	for(int i=1;i<=n;++i) {
		int x=read();
		solve(i,x);
	}
	while(m--) {
		int x=read(), y=read();
		solve(x,y);
		printf("%lld\n",ans);
	}
	// for(int i=1;i<=100;++i) printf("p[%lld]=%lld\n",i,p[i]);
}