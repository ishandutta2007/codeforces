#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,t;
ll a,b,c,d,e,f,g,h;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&a);
		scanf("%lld",&b);
		scanf("%lld",&c);
		scanf("%lld",&d);
		scanf("%lld",&e);
		scanf("%lld",&f);
		scanf("%lld",&g);
		scanf("%lld",&h);
		a-=d;
		b-=e;
		c-=f;
		if(a<0||b<0||c<0){puts("No");continue;}
		g-=a;
		h-=b;
		g=max(0ll,g);
		h=max(0ll,h);
		if(g>0||h>0){
			if(g+h>c){puts("No");continue;}
		}
		puts("Yes");
	}
}