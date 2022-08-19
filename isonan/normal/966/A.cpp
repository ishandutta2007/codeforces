#include <cstdio>
#include <set>
#define int long long
using std::min;

std::set<int>st,el;
int n,m,c1,c2,v,q,x1,x2,y1,y2;
int abs(int x){
	return x<0?-x:x;
}
signed main(){
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&c1,&c2,&v);
	for(int i=1,tem;i<=c1;i++)scanf("%I64d",&tem),st.insert(tem);
	for(int i=1,tem;i<=c2;i++)scanf("%I64d",&tem),el.insert(tem);
	scanf("%I64d",&q);
	for(int i=1;i<=q;i++){
		scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);
		int ans=10000000000000ll;
		int dis=abs(x1-x2);
		if(y1>y2)y1^=y2^=y1^=y2;
		if(x1==x2){
			printf("%I64d\n",y2-y1);
			continue;
		}
		if(el.size()){
			auto x=el.lower_bound(y1);
			if(x!=el.end()){
				if(*x<=y2)ans=min(ans,(y2-y1)+((dis+v-1)/v));
				else ans=min(ans,((*x)<<1ll)-y1-y2+((dis+v-1)/v));
			}
			if(x!=el.begin()){
				--x;
				ans=min(ans,y1+y2-((*x)<<1ll)+((dis+v-1)/v));
			}
		}
		if(st.size()){
			auto x=st.lower_bound(y1);
			if(x!=st.end()){
				if(*x<=y2)ans=min(ans,(y2-y1)+dis);
				else ans=min(ans,((*x)<<1ll)-y1-y2+dis);
			}
			if(x!=st.begin()){
				--x;
				ans=min(ans,y1+y2-((*x)<<1ll)+dis);
			}
		}
		printf("%I64d\n",ans);
	}
}