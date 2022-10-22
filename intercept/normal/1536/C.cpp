#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int M=5e5+9;
int n;
int d[M],k[M];
char s[M];
void work(){
	map<pii,int>mp;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i){
		d[i]=d[i-1];
		k[i]=k[i-1];
		if(s[i]=='D')d[i]++;
		else k[i]++;
	}
	for(int i=1;i<=n;++i){
		int x=d[i],y=k[i],z=__gcd(x,y);
		x/=z,y/=z;
		mp[pii{x,y}]++;
		printf("%d ",mp[pii{x,y}]);
	}
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}