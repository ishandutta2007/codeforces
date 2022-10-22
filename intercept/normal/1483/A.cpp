#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m;
vector<int>v[M];
int b[M],ans[M];
void work(){
	scanf("%d%d",&n,&m);
	int now=0,ma=0;
	for(int i=1;i<=n;++i)b[i]=0;
	for(int i=1,k;i<=m;++i){
		v[i].clear();
		scanf("%d",&k);
		for(int j=1,x;j<=k;++j){
			scanf("%d",&x);
			v[i].eb(x);
			b[x]++;
		}
	}
	for(int i=1;i<=n;++i){
		if(b[i]>(m+1)/2)now=i,ma=b[i];
	}
	for(int i=1;i<=m;++i){
		int y=0,z=0;
		for(auto o:v[i]){
			if(o!=now)y=o;
			if(o==now)z=o;
		}
		if(!z)ans[i]=y;
		else if(!y)ans[i]=now;
		else if(ma>(m+1)/2)ma--,ans[i]=y;
		else ans[i]=z;
	}
	if(ma>(m+1)/2)printf("NO\n");
	else {
		printf("YES\n");
		for(int i=1;i<=m;++i)printf("%d ",ans[i]);
		printf("\n");
	}
} 
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
4 6
1 1
2 1 2
3 1 2 3
4 1 2 3 4
2 2 3
1 3
*/