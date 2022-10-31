#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,x,y,w,res=2e9+5;

priority_queue<pair<int,int> >q[200500];
vector<pair<int,int> >v[200500];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&w);
		if((y-x+1)>=m)continue;
		v[x].push_back({y,w});
		q[y-x+1].push({-w,x});
	}
	for(i=1;i<=200000;i++){
		for(auto [x,y]:v[i]){
			k=x-i+1;
			while(!q[m-k].empty()){
				auto [xx,yy]=q[m-k].top();
				if(yy<=x){q[m-k].pop();}
				else{res=min(res,y-xx);break;}
			}
		}
	}
	printf("%d",(res>2000000000)?-1:res);
}