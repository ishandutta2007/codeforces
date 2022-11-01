#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include <assert.h>
#include<set>
#define rep(i,a,n) for(int i = a;i <= n;i++)
#define per(i,n,a) for(int i = n;i >= a;i--)
#define enter puts("")

using namespace std;
typedef long long ll;
const int M = 200005;

ll read(){
	ll ans = 0,op = 1LL;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') op = -1LL;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ans *= 10LL;
		ans += (ll)(ch - '0');
		ch = getchar();
	}
	return ans * op;
}
struct bridge{
	ll length,posi;
	bool operator < (const bridge &g)const{
		return length < g.length;
	}
}br[M];
struct seg{
	ll l,r,pos;
	bool operator < (const seg &g) const{
		if(l == g.l) return r < g.r;
		return l < g.l;
	}
}a[M],c[M];
struct node{
	ll l,r,pos;
	bool operator < (const node &g)const{
		if(r!=g.r) return r < g.r;
		return pos < g.pos;
	}
	bool operator != (const node &g)const{
		return pos != g.pos;
	}
}d[M];
ll n,m,b[M],p = 1,ans[M],tot = 0;
multiset<node> q;
int main(){
	n = read();m = read();
	rep(i,1,n) a[i].l = read(),a[i].r = read();
	rep(i,1,m) br[i].length = read(),br[i].posi = i;sort(br+1,br+1+m);
//	rep(i,1,m) printf("#%lld %lld\n",br[i].length,br[i].posi);
	rep(i,2,n) c[i-1].l = a[i].l - a[i-1].r,c[i-1].r = a[i].r - a[i-1].l,c[i-1].pos = i-1;
	sort(c+1,c+n);
//	rep(i,1,n-1) printf("#%lld %lld\n",c[i].l,c[i].r);
	rep(i,1,n-1) d[i].l = c[i].l,d[i].r = c[i].r,d[i].pos = c[i].pos;
//	rep(i,1,n-1) printf("!%lld %lld %lld\n",d[i].l,d[i].r,d[i].pos);
	rep(i,1,m){
		if(tot == n-1) break;
		while(d[p].l <= br[i].length && p <= n-1){
			assert(d[p].l);
			q.insert(d[p++]);
		}
		if(q.empty()) continue;
		node now = *(q.begin());
//		printf("*%lld %lld\n",now.l,now.r);
		if(now.r < br[i].length){
			printf("No\n");
			return 0;
		}
		ans[now.pos] = br[i].posi;
		q.erase(now),tot++;
	}
	if( tot < n-1 ){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	rep(i,1,n-1) printf("%I64d ",ans[i]);
	return 0;
}