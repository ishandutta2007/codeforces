#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,l,r,md;
ll res,b[200500],c[200500];

struct sb{ll x,y;}s[200500],s1;
bool cross(sb i,sb j,sb k){return ((k.y-j.y)*(j.x-i.x)-(j.y-i.y)*(k.x-j.x))<=0;}
ll get(sb x){
	res=max(res,c[i]+x.y+x.x*b[i]);
	return c[i]+x.y+x.x*b[i];
}

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		b[i]=b[i-1]+k;
		c[i]=c[i-1]+1ll*k*i;
		res=max(res,1ll*k);
		get(s[it]);get(s[1]);
		l=1;r=it-1;
		while(l<=r){
			md=(l+r)/2;
			if(get(s[md])<get(s[md+1])){
				l=md+1;
			}
			else r=md-1;
		}
		s1.x=-(i-1);
		s1.y=(i-1)*b[i-1]-c[i-1];
		while(it>=2&&cross(s[it-1],s[it],s1))it--;
		s[++it]=s1;
	}
	printf("%lld",res);
}