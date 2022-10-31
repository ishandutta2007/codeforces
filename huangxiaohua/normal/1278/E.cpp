#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,l[500500],r[500500],a[500500],mn,mx,it,x,y;
vector<int> v[500500];

void dfs(int x,int fa,int cur=mx){
	r[x]=cur;
	for(auto i:v[x]){
		if(i==fa){continue;}
		l[i]=--cur;mn=min(mn,cur);
		mx+=a[i];
		dfs(i,x);
	}
	if(x==1){l[x]=mn-1;mn-=2;}
}

int main(){
    scanf("%d",&n);
    for(i=1;i<n;i++){
    	scanf("%d%d",&x,&y);
    	v[x].push_back(y);
    	v[y].push_back(x);
    	a[x]++;a[y]++;
	}
	dfs(1,0);
	for(i=1;i<=n;i++){
		printf("%d %d\n",l[i]-mn,r[i]-mn);
	}
}