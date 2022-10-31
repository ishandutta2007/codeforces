#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,x,y,z;
ll res,sum,cl,cr,my[500500],mz[500500],a[500500];
vector<pair<ll,ll> > v[500500];
void add(int x,ll z){
	x=y+1-x;for(;x<=y;x+=(-x&x)){a[x]=max(a[x],z);}
}
ll get(int x,ll res=0){
	x=y+1-x;for(;x;x-=(-x&x)){res=max(res,a[x]);}return res;
}

int main(){
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&j,&k,&m);
		v[j].push_back({k,m});
	}
	for(i=x;i>=1;i--){
		my[i]=my[i+1];mz[i]=mz[i+1];
		for(auto [j,k]:v[i]){
			my[i]=max(my[i],j);
			mz[i]=max(mz[i],k);
		}
	}
	for(i=1;i<=x;i++){
		res+=(y-my[i])*(z-mz[i]);
		res-=sum;
		for(auto [j,k]:v[i]){add(j,k);}
		if(!cl){
			if(get(my[i+1]+1)<=mz[i+1]){continue;}
			cl=cr=my[i+1]+1;sum+=get(cl)-mz[i+1];
		}
		else{sum+=(mz[i]-mz[i+1])*(cr-cl+1);}
		while(cl>my[i+1]+1){
			if(get(cl-1)<=mz[i+1]){break;}
			cl--;sum+=get(cl)-mz[i+1];
		}
		while(cr<y){
			if(get(cr+1)<=mz[i+1]){break;}
			cr++;sum+=get(cr)-mz[i+1];
		}
	}
	printf("%lld",res);
}