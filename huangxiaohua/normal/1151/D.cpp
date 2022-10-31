#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

struct sb{
	ll x,y,z;
}s[100500];
bool cmp(sb a,sb b){
	return a.z>b.z;
}

int n,x,y,i,j;
ll res;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&s[i].x,&s[i].y);
		s[i].z=s[i].y-s[i].x;
	}
	sort(s+1,s+n+1,cmp);
	for(i=1;i<=n;i++){
		res+=(i-1)*s[i].y;
		res+=(n-i)*s[i].x;
	}
	printf("%lld",res);
}