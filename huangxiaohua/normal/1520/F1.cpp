#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,a[200500],t,k;
int mp[200500];

void add(int x){
	for(;x<=n;x+=(-x&x)){a[x]++;}
}

int get(int x){
	int res=0;
	for(;x;x-=(-x&x)){res+=a[x];}return res;
}

int ask(int x){
	int res;
	if(mp[x]!=-1){return mp[x]+get(x);}
	printf("? 1 %d\n",x);fflush(stdout);
	scanf("%d",&res);
	mp[x]=res-get(x);
	return res;
}

void answer(int x){
	printf("! %d\n",x);fflush(stdout);add(x);
}

int main(){
	scanf("%d%d",&n,&t);
	memset(mp,-1,sizeof(mp));
	while(t--){
		scanf("%d",&k);
		int l=1,r=n,md,res=200500,tmp;
		while(l<=r){
			md=(l+r)/2;
			tmp=ask(md);
			if(md-tmp==k){
				res=min(res,md);r=md-1;continue;
			}
			if(md-tmp>k){
				r=md-1;continue;
			}
			if(md-tmp<k){
				l=md+1;
			}
		}
		answer(res);
	}
}