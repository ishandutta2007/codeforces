#include <bits/stdc++.h>
using namespace std;

map<int, map<int, int>> mp;
int i,j,k,n,m,t,it,op;
void add(int x,int y,int z){for(;y<=1e9;y+=(-y&y)){mp[x][y]+=z;}}
int get(int x,int y,int z=0){for(;y;y-=(-y&y)){z+=mp[x][y];}return z;}
#define SB scanf("%d%d",&i,&j);

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&op);
		if(op==1){SB;add(j,i,1);}
		if(op==2){SB;add(j,i,-1);}
		if(op==3){SB;printf("%d\n",get(j,i));}
	}
}