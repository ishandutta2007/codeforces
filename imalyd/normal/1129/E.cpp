#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,sz[N],in,q[N],L[N],R[N];
vector<int>x,y;
bool cmp(int a,int b){return sz[a]<sz[b];}
int ask(int s,vector<int> e,int v){
    if(!s)return 0;
	printf("1\n1\n%d\n",s);
	for(int i=0;i<s;i++)printf("%d ",e[i]);
	printf("\n%d\n",v);fflush(stdout);
	scanf("%d",&in);return in;
}
int main(){
    scanf("%d",&n);sz[1]=n;
	for(int i=1;i<=n;i++)q[i]=i;
	for(int i=2;i<=n;i++)y.push_back(i);
    for(int i=2;i<=n;i++)sz[i]=ask(n-1,y,i);
	for(int i=1;i<=n;i++)if(sz[i]==1)x.push_back(i);
	sort(q+1,q+n+1,cmp);
	//for(int i=1;i<=n;i++)printf("q[%d]=%d\n",i,q[i]);
	for(int i=1;i<=n;i++){
		int v=q[i];if(sz[v]==1)continue;int sz=x.size(),k=ask(sz,x,v);
		//printf("v=%d sz=%d k=%d\n",v,sz,k);
		while(k){
			int l=0,r=sz-1,mid,ans;
			while(l<=r){
				mid=l+r>>1;
				if(ask(mid,x,v)==k)r=mid-1;
				else{ans=mid;l=mid+1;}
			}
			L[++L[0]]=v;R[L[0]]=x[ans];
			x[ans]=x[--sz];x.pop_back();--k;
		}
		x.push_back(v);
	}
	printf("ANSWER\n");
	for(int i=1;i<n;i++)printf("%d %d\n",L[i],R[i]);
	return 0;
}