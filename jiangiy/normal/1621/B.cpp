#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		int n;
		scanf("%d",&n);
		std::pair<PI,int>a=MP(MP(-1e9,0),0),b=MP(MP(0,0),0);
		int tc=2e9;
		for(int i=1;i<=n;i++){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			int tl=a.fi.fi,tr=b.fi.fi;
			a=std::max(a,MP(MP(-l,-c),r));
			b=std::max(b,MP(MP(r,-c),-l));
			if(a.fi.fi!=tl||b.fi.fi!=tr)tc=2e9;
			if(-l==a.fi.fi&&r==b.fi.fi)tc=std::min(tc,c);
			printf("%d\n",std::min(-a.fi.se-b.fi.se,tc));
		}
	}
}