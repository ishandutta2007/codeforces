#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e5+9;
int n;
ll sum,ans;
struct P{ll a,b;}c[M];
bool cmp(P&l,P&r){
	return l.b<r.b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&c[i].a,&c[i].b);
	sort(c+1,c+n+1,cmp);
	for(int l=1,r=n;l<=r;++l){
		while(sum<c[l].b&&l<=r){
			if(c[r].a>=c[l].b-sum){
				ans+=2ll*(c[l].b-sum);
				c[r].a-=c[l].b-sum;
				sum=c[l].b;
				if(!c[r].a)r--;
			}
			else {
				ans+=2ll*c[r].a;
				sum+=c[r].a;
				c[r].a=0;
				r--;
			}
		}
		ans+=c[l].a;
		sum+=c[l].a;
	}
	printf("%lld\n",ans);
	return 0;
}