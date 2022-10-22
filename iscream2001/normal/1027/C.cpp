#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long 
using namespace std;
const int inf=1e9;
int n,top;
int a[1000005];
int q[10050];
int t[10050];
int main(){
	int T;scanf("%d",&T);
	int x,A,B;
	bool flag=0;
	while(T--){
		scanf("%d",&n);top=0;flag=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			++t[a[i]];
			if(t[a[i]]==2) q[++top]=a[i];
			if(t[a[i]]>=4){
				flag=1;x=a[i];
			}
		}
		for(int i=1;i<=n;++i) t[a[i]]=0;
		if(flag){
			printf("%d %d %d %d\n",x,x,x,x);
			continue;
		}
		sort(q+1,q+1+top);
		A=0;B=10005;
		for(int i=1;i<top;++i){
			if(A*q[i+1]<B*q[i]){
				A=q[i];B=q[i+1];
			}
		}
		printf("%d %d %d %d\n",A,A,B,B);
	}
	return 0;
}