#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
int query(vector<int> A,int sza,vector<int> B,int szb,int T){
	printf("%d\n",sza);
	for(int i=0;i<sza;i++)printf("%d ",A[i]);puts("");
	printf("%d\n",szb);
	for(int i=0;i<szb;i++)printf("%d ",B[i]);puts("");
	printf("%d\n",T);
	fflush(stdout);
	int ans=0;scanf("%d",&ans);
	return ans;
}
const int N=510;
int n;
vec t;vec node;
int del[N];int sz[N];


bool cmp(const int a,const int b){return sz[a]>sz[b];}

struct edge{
	int u,v;
	edge(int u=0,int v=0):u(u),v(v){}
}e[N];int cnt=0;

int qry(int l,int r,int id){
	vector<int>Q;
	Q.resize(0);
	for(int i=l;i<=r;i++)if(!del[node[i]]){
		Q.push_back(node[i]);
	}
	if(Q.size()==0)return 0;
	return query((vector<int>){1,1},1,Q,Q.size(),id);
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		t.push_back(i);
	}
	sz[1]=n;
	node.push_back(1);
	for(int i=2;i<=n;i++){
		sz[i]=query((vector<int>){1,1},1,t,n-1,i);
		node.push_back(i);
//		cout<<i<<","<<sz[i]<<endl;
	}
//	puts("----");
	sort(node.begin(),node.end(),cmp);
	for(int i=n-1;~i;i--){
		int x=node[i];
//		cout<<x<<" "<<sz[x]<<"::"<<endl;
		sz[x]--;
		if(sz[x]==0)continue;
		while(qry(i+1,n-1,x)){
			int l=i+1,r=n-1;
			while(l<r){
				int mid=(l+r)>>1;
				int ret=qry(i+1,mid,x);
				if(ret==0){
					l=mid+1;
				}else{
					r=mid;
				}
			}
			e[++cnt]=edge(x,node[l]);
			sz[x]--;del[node[l]]=1;
		}
	}
	puts("ANSWER");
	for(int i=1;i<=cnt;i++)cout<<e[i].u<<" "<<e[i].v<<endl;
}