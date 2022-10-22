#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL P=998244353;
const int N=1e5+100;
const double PI=acos(-1);
const int E=320;
int n,K;
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		int j;
		for(j=1;j<=n;++j){
			if(a[j]<a[j+1]&&j<n) break;
		}
		if(j>n){
			puts("YES");
			continue;
		}
		int x=a[j],y=a[j+1]-a[j];
		bool flag=0;
		for(int i=j+2;i<=n;++i){
			if(a[i]<y){
				flag=1;break;
			}
			a[i]-=y;
			if(a[i]<=x){
				x=min(x,a[i]);
				continue;
			}
			a[i]-=x;
			y+=a[i];
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
/*
4 4
3 0 1 2
2 1 0 2
3 2 1 1
1 1 0 2
*/