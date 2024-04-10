#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct atom{
	int l,r,where;
}x[201000];
int compare(atom k1,atom k2){
	return k1.l<k2.l;
}
struct atom2{
	int l,r;
};
int operator < (const atom2 k1,const atom2 k2){
	return k1.l<k2.l;
}
priority_queue<atom2>Q;
int p[201000],n,m,where[201000];
long long A[201000],ans[201000];
void add(int k1){
//	cout<<"add "<<k1<<endl;
	for (;k1<=n;k1+=k1&(-k1)) A[k1]+=1;
}
long long find(int k1){
	long long ans=0; for (;k1;k1-=k1&(-k1)) ans+=A[k1]; //cout<<k1<<" "<<ans<<endl; 
	return ans;
}
void addin(int k1,int k2){
	if (k1<=where[k2]){add(where[k2]); return;}
	Q.push((atom2){where[k2],k1});
}
int main(){
	scanf("%d%d",&n,&m); for (int i=1;i<=n;i++){ scanf("%d",&p[i]); where[p[i]]=i;}
	for (int i=1;i<=m;i++) scanf("%d%d",&x[i].l,&x[i].r); for (int i=1;i<=m;i++) x[i].where=i;
	sort(x+1,x+m+1,compare);
	memset(A,0x00,sizeof A); int now=m;
	for (int i=n;i;i--){
		while (!Q.empty()&&Q.top().l==i){add(Q.top().r); Q.pop();}
		for (int j=1;j*p[i]<=n;j++) addin(i,j*p[i]);
		while (now&&x[now].l==i){ans[x[now].where]=find(x[now].r); now--;}
	}
	for (int i=1;i<=m;i++) printf("%I64d\n",ans[i]); return 0;
}