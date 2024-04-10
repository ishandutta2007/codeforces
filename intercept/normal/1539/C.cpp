#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+9;
int n,ans=1;
ll k,x,a[M];
map<ll,int>b;
int main(){
	scanf("%d%lld%lld",&n,&k,&x);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		b[max(0ll,a[i]-a[i-1]-1)/x]++;
	}
	for(auto o:b){
		while(o.second){	
			if(k>=o.first)k-=o.first,o.second--;
			else {
				ans+=o.second;break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}