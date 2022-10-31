// Hydro submission #62c6d1f9c3a9fda5622b1a90@1657197050918
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Int;
const int N=12e5+1,mod=1e9+7;
int n,m,ans[N],dep[N],cnt[N],vis[N],tot;
vector<int> q[N];
vector<pair<int,int> > e[N];
priority_queue<Int,vector<Int>,greater<Int> > Q;
vector<int> E[N][10];
void add(int x,int y,int z){
	if(z<10)E[x][z].push_back(y);
    else{
        E[++tot][z%10].push_back(y);
        z/=10;
        while(z>=10)E[++tot][z%10].push_back(tot-1),z/=10;
        E[x][z].push_back(tot);
    }
}
void Joseph_Stalin(){
    scanf("%d%d",&n,&m);tot=n;
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        add(x,y,i),add(y,x,i);
    }
    q[1].push_back(1);
    int tail=1;
    for(int i=1;i<=tail;i++){
    	for(int j=0;j<=9;j++){
    		for(int x:q[i]){
    			for(int y:E[x][j]){
    				if(!vis[y]){
    					ans[y]=(10ll*ans[x]%mod+j)%mod;
    					vis[y]=1;
    					q[tail+1].push_back(y);
					}
				}
			}
			if(q[tail+1].size())tail++;
		}
	}
    for(int i=2;i<=n;i++)printf("%d\n",ans[i]);
}
int _=1;
int main(){
    while(_--)Joseph_Stalin();
}