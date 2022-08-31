#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
ll h;
int n,m,k;
ll a[100005];int c[100005];
vector<int>t[10005];
struct cmpcgtr{
	int operator()(int i,int j){
		if(c[i]==c[j])return j>i;
		return c[i]>c[j];
	}
};
ll dis[10005];
set<int,cmpcgtr> qu;
void init(){
	qu.clear();
	for (int i=0;i<k;i++)
		for (int j=0;j<t[i].size();j++)if(a[t[i][j]]>=dis[i] && c[t[i][j]]>0)qu.insert(t[i][j]);
}
int que[10005],inq[10005];
void ins(ll d){
	int p=0,q=0;
	for (int i=0;i<k;i++)if(dis[i]<=h){
		que[q++]=i;
		inq[i]=1;
	}
	while(p!=q){
		int u=que[p++],v=(u+d)%k;if(p==10005)p=0;inq[u]=0;
		if(dis[u]+d<=dis[v]){
			dis[v]=dis[u]+d;
			if(!inq[v]){
				inq[v]=1;
				que[q++]=v;
				if(q==10005)q=0;
			}
		}
	}
	init();
}
	
int main()
{
	cin>>h>>n>>m>>k;
	for (int i=1;i<=n;i++)scanf("%I64d%d",&a[i],&c[i]);
	for (int i=1;i<=n;i++)t[a[i]%k].push_back(i);
	for (int i=0;i<k;i++)dis[i]=h+1;
	dis[1]=1;
	init();
	while(m--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			ll dx;
			scanf("%I64d",&dx);
			ins(dx);
		}else if(opt==2){
			int x,y;scanf("%d%d",&x,&y);
			if(qu.find(x)!=qu.end()){
				qu.erase(x);
				c[x]-=y;
				qu.insert(x);
			}else c[x]-=y;
		}else{
			if(qu.empty())printf("0\n");
			else{
				int i=*qu.begin();
				qu.erase(qu.begin());
				printf("%d\n",c[i]);
				c[i]=0;
			}
		}
	}
	return 0;
}