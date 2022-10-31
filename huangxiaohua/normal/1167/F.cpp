#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t;
ll res,sum1,sum2,f1[500500],f2[500500],t1,t2;

void add(ll *f,int x,ll y){for(;x<=n;x+=(-x&x)){f[x]+=y;}}
ll get(ll *f,int x,ll y=0){for(;x;x-=(-x&x)){y+=f[x];}return y;}
vector<pair<int,int> >v;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);v.push_back({k,i});
	}
	sort(v.begin(),v.end());
	for(auto [i,j]:v){
		t1=get(f1,j);t2=get(f2,j);
		res=(res+(n-j+1)*t2%M*i+j*((sum1-t1)*(n+1)-(sum2-t2))%M*i+1ll*j*(n+1-j)%M*i)%M;
		sum1++;sum2+=j;
		add(f1,j,1);add(f2,j,j);
	}
	printf("%lld",res);
}