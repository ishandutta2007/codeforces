#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,a[1100],p[1100],q[1100];
int ans; pii Ans[1100000];
inline bool cmp(int x,int y){ return a[x]<a[y]||a[x]==a[y]&&x<y;}
inline void myswap(int x,int y){
	Ans[++ans]=pii(x,y);
	swap(q[x],q[y]);
	p[q[x]]=x; p[q[y]]=y;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++) q[p[i]]=i;
	while (n){
		for (int i=q[n]+1;i<=n;i++) myswap(p[i],n);
		n--;
	}

	printf("%d\n",ans);
	for (int i=1;i<=ans;i++) printf("%d %d\n",Ans[i].first,Ans[i].second);
	return 0;
}