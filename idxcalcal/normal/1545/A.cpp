#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n;
#define Maxn 100010
int a[Maxn];
pii b[Maxn];
pii c[Maxn];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);
		rep(i,1,100000)b[i].FR=b[i].SE=c[i].FR=c[i].SE=0;
		rep(i,1,n){
			rd(a[i]);
			if(i&1)b[a[i]].FR++;
			else b[a[i]].SE++;
		}
		sort(a+1,a+n+1);
		rep(i,1,n){
			if(i&1)c[a[i]].FR++;
			else c[a[i]].SE++;
		}
		bool fl=true;
		rep(i,1,100000)
			if(b[i].FR!=c[i].FR||b[i].SE!=c[i].SE){
				fl=false;
				break;
			}
		if(fl)puts("YES");
		else puts("NO");
	}
	return 0;
}