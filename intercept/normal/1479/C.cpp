#include<bits/stdc++.h>
using namespace std;
int m,l,r;
struct P{int u,v,w;};
vector<P>g;
void add(int u,int v,int w){g.push_back(P{u,v,w});m++;}
int main(){
	scanf("%d%d",&l,&r);
	add(1,22,l);
	for(int i=2;i<=21;++i)add(1,i,l);
	for(int i=2;i<=20;++i)
		for(int j=i+1;j<=21;++j)
			add(i,j,1<<i-2);
	for(int t=r-l,i=2;i<=21;++i){
		if(t&(1<<i-2))t^=1<<i-2,add(i,22,t+1); 
	}
	printf("YES\n22 %d\n",m);
	for(auto o:g)printf("%d %d %d\n",o.u,o.v,o.w);
	return 0;
}