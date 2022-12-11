#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct atom{
	int where,w;
}A[110000];
int n,w[110000];
int compare(atom k1,atom k2){
	return k1.where<k2.where;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&A[i].where,&A[i].w);
	sort(A+1,A+n+1,compare); int an=0;
	for (int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while (l<r){
			int mid=(l+r)>>1;
			if (A[mid].where<A[i].where-A[i].w){
				ans=mid; l=mid+1;
			} else r=mid;
		}
		w[i]=w[ans]+1; an=max(an,w[i]);
	}
	cout<<n-an<<endl; return 0;
}