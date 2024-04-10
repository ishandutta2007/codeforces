#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sb{
	ll x,y;
}s[5050];

int i,j,k,n,res[5050];

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    	scanf("%lld%lld",&s[i].x,&s[i].y);
    	res[i]=i;
	}
	for(j=3;j<=n;j++){
		for(i=j;i>=3;i--){
			if(((s[res[i]].x-s[res[i-1]].x)*(s[res[i-2]].x-s[res[i-1]].x)+(s[res[i]].y-s[res[i-1]].y)*(s[res[i-2]].y-s[res[i-1]].y))<=0){swap(res[i],res[i-1]);}
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
}