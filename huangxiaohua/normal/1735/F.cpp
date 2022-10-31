#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

int i,j,k,n,m,t;
ld res,cur,f[1000005],len[1000005],cur2;
const ld NMSL=1e-9;

int main() {
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d%lf%lf",&n,&res,&cur);
		cur2=res;
		multiset<pair<ld,ld> >s;
		for(i=1;i<=n;i++)scanf("%lf",&f[i]);
		for(i=1;i<=n;i++){
			scanf("%lf",&len[i]);
			f[i]/=len[i];
		}
		if(!res&&!cur){
			while(n--)puts("0");
			continue;
		}
		for(i=1;i<=n;i++){
			s.insert({f[i],len[i]*2});
			res+=f[i]*len[i];
			cur-=len[i];
			cur2-=f[i]*len[i];
			while(cur2<NMSL&&!s.empty()){
				auto [k,l]=*--s.end();
				s.erase(--s.end());
				if(l*k+cur2<NMSL){
					cur2+=l*k;
				}
				else{
					l+=(cur2/k);
					cur2=0;
					s.insert({k,l});
					break;
				}
			}
			while(cur<NMSL&&!s.empty()){
				auto [k,l]=*s.begin();
				s.erase(s.begin());
				if(l+cur<NMSL){
					cur+=l;
					res-=k*l;
				}
				else{
					l+=cur;
					res+=k*cur;
					cur=0;
					s.insert({k,l});
					break;
				}
			}
			printf("%.20lf\n",res);
		}
	}
}