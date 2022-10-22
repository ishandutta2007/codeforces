#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n; vector<pii> ans;
void solve(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid); solve(mid+1,r);
	for (int i=l;i<=mid;i++) printf("%d %d\n",i,i-l+mid+1);
}
int main(){
	scanf("%d",&n); if (n==1){ puts("0"); return 0;}
	int k=1;
	while ((1<<(k+1))<n) k++;
	printf("%d\n",k*(1<<k));
	solve(1,1<<k); solve(n-(1<<k)+1,n);
	return 0;
}