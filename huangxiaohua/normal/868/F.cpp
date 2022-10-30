#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t,a[100500],cur[100500],L=1,R;
ll tmp,f[21][100500];

void add(int l,int r){
	while(L>l){L--;tmp+=cur[a[L]];cur[a[L]]++;}
	while(L<l){cur[a[L]]--;tmp-=cur[a[L]];L++;}
	while(R>r){cur[a[R]]--;tmp-=cur[a[R]];R--;}
	while(R<r){R++;tmp+=cur[a[R]];cur[a[R]]++;}
}

void get(int l1,int r1,int l,int r){
	if(l1>r1||l>r)return;
	int md=(l+r)>>1,cur;
	ll res=1e18;
	for(int i=l1;i<=r1;i++){
		add(i,md);
		if(f[t-1][i-1]+tmp<res){res=f[t-1][i-1]+tmp;cur=i;}
	}
	f[t][md]=res;
	get(l1,cur,l,md-1);
	get(cur,r1,md+1,r);
}

int main(){
	memset(f,1,sizeof(f));
	f[0][0]=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	for(t=1;t<=m;t++){	get(1,n,1,n);}
	printf("%lld",f[m][n]);
}