#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 600005
#define find() k=*lower_bound(st[N+f[r]+f[l-1]].begin(),st[N+f[r]+f[l-1]].end(),l);printf("%d\n",k)
int i,j,k,t,n,m,f[300500],q,l,r;
char c;
vector<int> st[2005000];

int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++){
			c=getchar();
			if(c=='+'||c=='-'){
				f[i]=f[i-1]+((c=='+')?1:-1)*((i&1)?1:-1);
			}
			else{i--;}
		}
		for(i=1;i<=n;i++){
			st[N+f[i]+f[i-1]].emplace_back(i);
		}
		while(q--){
			scanf("%d%d",&l,&r);
			if((r-l+1)&1){
				puts("1");
				find();
			}
			else{
				if(f[r]==f[l-1]){
					puts("0");
				}
				else{
					puts("2");
					printf("%d ",r);r--;
					find();
				}
			}
		}
		for(i=1;i<=n;i++){
			if(!st[N+f[i]+f[i-1]].empty()){st[N+f[i]+f[i-1]].clear();}
		}
	}
}