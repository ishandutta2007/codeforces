#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#define LL long long
using namespace std;
const int N=10000;
int n;
int a[N],b[N];
char s[N],t[N];
int c=0;
int ans[10000000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		cin>>s[i];
		++a[s[i]];
	}
	for(int i=1;i<=n;++i){
		cin>>t[i] ;
		++b[t[i]];
	}
	for(int i=1;i<=5000;++i){
		if(a[i]!=b[i]){
			printf("-1\n");return 0;
		}
	}
	for(int i=1;i<=n;++i){
		int j;
		for(j=i;j<=n;++j){
			if(s[j]==t[i])break;
		}
		if(j!=i){
			for(int k=j-1;k>=i;--k){
				++c;ans[c]=k;swap(s[k],s[k+1]);
			}
		}
	}
	printf("%d\n",c);
	for(int i=1;i<=c;++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
/*
*/