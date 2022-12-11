#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int f[210000],n,m;
set<int>S;
int findfather(int k){
	if (f[k]==k) return k; f[k]=findfather(f[k]); return f[k];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=n;i++) S.insert(i);
	S.insert(0);
	for (;m;m--){
		int k1; scanf("%d",&k1);
		if (k1==1){
			int k2,k3; scanf("%d%d",&k2,&k3);
			k2=findfather(k2); k3=findfather(k3);
			f[k2]=k3;
		} else if (k1==2) {
			int l,r; scanf("%d%d",&l,&r); 
			set<int>::iterator k=S.lower_bound(r);
			int now=findfather((*k)); k--;
			while ((*k)>=l){
				int k2=findfather(*k),k3=(*k); f[k2]=now; k--; S.erase(k3);
			}
		} else {
			int k2,k3; scanf("%d%d",&k2,&k3);
			if (findfather(k2)==findfather(k3)) printf("YES\n"); else printf("NO\n");
		}
	}
	return 0;
}