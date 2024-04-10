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
int d[Maxn];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(d[i]);
		sort(d+1,d+n+1);
		ll Ans=d[n];
		rep(i,2,n)Ans-=1ll*(i-1)*d[i];
		rep(i,1,n-1)Ans+=1ll*(n-i)*d[i];
		printf("%lld\n",Ans);
	}
	return 0;
}