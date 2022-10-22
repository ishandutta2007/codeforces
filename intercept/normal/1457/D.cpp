#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n;
int a[M],b[M],c[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	} 
	if(n>64){
		printf("1");
		return 0;
	} 
	for(int len=1;len<=n;++len){
		for(int l=1;l<=n;++l){
			int r=l+len;
			if(r>n)break;
			for(int k=l;k<r;++k){
				int x=a[k]^a[l-1];
				int y=a[r]^a[k];
				if(y<x){
				//	cout<<l<<" "<<k<<" "<<r<<endl;
					printf("%d",len-1);
					return 0;
				}
			}
			
		}
	}
	printf("-1");
	return 0;
}
/*
4
2 5 6 8
*/