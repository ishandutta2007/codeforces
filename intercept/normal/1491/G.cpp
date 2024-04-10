#include<bits/stdc++.h>
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,x,a[M];
bool vis[M];
vector<int>c;
vector<pii>op;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			for(int j=i;!vis[j];j=a[j])vis[j]=1;
			if(a[i]==i)continue;
			if(!x)x=i;
			else {
				op.eb(pii{i,x});
				for(int j=a[i];j!=i;j=a[j])op.eb(pii{j,x});
				for(int j=a[x];j!=x;j=a[j])op.eb(pii(j,i));
				op.eb(pii{x,i});
				x=0;
			}
		}
	}
	if(x){
		c.eb(x);
		for(int j=a[x];j!=x;j=a[j])c.eb(j);
		int s=c.size();
		if(s==2){
			int y;
			for(int i=1;i<=3;++i){
				if(c[0]!=i&&c[1]!=i)y=i;
			}
			op.eb(pii{c[0],y});
			op.eb(pii{c[1],y});
			op.eb(pii{c[0],y});
		}
		if(s==3){
			op.eb(pii{c[0],c[1]});
			op.eb(pii{c[1],c[2]});
			op.eb(pii{c[2],c[0]});
			op.eb(pii{c[0],c[1]});
		}
		if(s>=4){
			op.eb(pii{c[0],c[s-3]});
			op.eb(pii{c[s-3],c[s-2]});
			op.eb(pii{c[s-2],c[s-1]});
			op.eb(pii{c[s-1],c[1]});
			for(int j=2;j<=s-4;++j)op.eb(pii{c[j],c[s-1]});
			op.eb(pii{c[0],c[s-2]});
			if(s>4)op.eb(pii{c[s-1],c[s-3]});
		}	
	}
	printf("%d\n",op.size());
	for(auto o:op)printf("%d %d\n",o.first,o.second);
	return 0;
	return 0;
}
/*
5
3 1 2 5 4
*/