#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sb{
	ll a,b;
}s[200500];

bool cmp(sb x,sb y){return x.a<y.a;}

int i,j,n,t;
ll res,tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res=1145141919;tmp=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&s[i].a);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&s[i].b);tmp+=s[i].b;
		}
		sort(s+1,s+n+1,cmp);res=min(tmp,res);
		for(i=1;i<=n;i++){
			tmp-=s[i].b;res=min(res,max(s[i].a,tmp));
		}printf("%lld\n",res);
	}
}