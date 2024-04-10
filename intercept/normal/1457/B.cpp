#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n,k;
int c[M];
void work(){
	int mi=1e9;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=100;++i){
		int l=1,ans=0;
		while(l<=n){
			if(c[l]==i){l++;continue;}
			ans++;
			l+=k;
		}
		mi=min(mi,ans);
	}
	printf("%d\n",mi);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}