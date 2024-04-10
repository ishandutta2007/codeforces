#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[310000];
struct Hash_BIT{
	int Mod,pw[310000];
	struct BIT{
		ll tree[310000];
		void add(int x,int y){
			for (;x<=n;x+=x&-x) tree[x]+=y;
		}
		ll query(int x){
			ll res=0;
			for (;x;x-=x&-x) res+=tree[x];
			return res;
		}
	} T1,T2;
	void init(int m){
		Mod=m; pw[0]=1;
		for (int i=1;i<=n;i++) pw[i]=pw[i-1]*2%Mod;
	}
	void upd(int x){
		T1.add(x,pw[x-1]);
		T2.add(x,pw[n-x]);
	}
	bool check(int x,int len){
		ll a=(T1.query(x)%Mod-T1.query(x-len)%Mod+Mod)%Mod;
		ll b=(T2.query(x+len-1)%Mod-T2.query(x-1)%Mod+Mod)%Mod;
		if (x-1<n-x) return (a*pw[(n-x)-(x-1)]%Mod!=b);
		else return (a!=b*pw[(x-1)-(n-x)]%Mod);
	}
} H1,H2;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	H1.init(1e9+7); H2.init(1e9+9);
	for (int i=1;i<=n;i++){
		H1.upd(a[i]); H2.upd(a[i]);
		int len=min(a[i],n-a[i]+1);
		if (H1.check(a[i],len)&&H2.check(a[i],len)){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}