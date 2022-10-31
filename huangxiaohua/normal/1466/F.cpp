#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,n,t,t2,x,y,fa[500500],size[500500],tmp,fx,fy,m,k;
ll res=1;
vector<int> v;

int find(int k){
	if(!fa[k]){return 0;}
	if(fa[k]==k){return k;}
	return fa[k]=find(fa[k]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		fa[i]=i;
	}
	for(i=1;i<=n;i++){
		
		scanf("%d",&k);
		if(k==1){
			scanf("%d",&x);
			fx=find(x);
			if(!size[fx]){
				size[fx]=1;
				res=res*2%M;
				v.push_back(i);
			}
			continue;
		}
		else{
			scanf("%d%d",&x,&y);
			fx=find(x);fy=find(y);
			if(fx==fy){
				continue;
			}
			if(!size[fx]&&!size[fy]){
				fa[fx]=fy;
				res=res*2%M;
				v.push_back(i);
				continue;
			}
			if(size[fx]&&size[fy]){
				continue;
			}
			size[fx]=size[fy]=1;
			res=res*2%M;
			v.push_back(i);
		}
	}
	printf("%lld %d\n",res,v.size());
	for(i=0;i<v.size();i++){
		printf("%d ",v[i]);
	}
}