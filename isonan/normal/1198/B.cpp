#include <cstdio>
#include <vector>

int n,q,a[200001],fstchange[200001],maxeq[200001];
std::vector<std::pair<int,int> >vec;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	scanf("%d",&q);
	for(int i=1,opt,p,x;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&p,&x);
			a[p]=x;
			fstchange[p]=i;
		}
		else if(opt==2){
			scanf("%d",&x);
			maxeq[i]=x;
		}
	}
	for(int i=q-1;i;--i)maxeq[i]=std::max(maxeq[i],maxeq[i+1]);
	for(int i=1;i<=n;i++)printf("%d ",std::max(a[i],maxeq[fstchange[i]+1]));
}