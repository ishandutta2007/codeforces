#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back

const int k=21;
 
int n;
vector<int> are[MAXN];
int h[MAXN];
int lc[k][MAXN];
 
//node, parent, height
void lca_dfs(int u, int p){
	if(u==p)h[u]=0;
	else h[u]=h[p]+1;
	lc[0][u]=p;
	for(int i=1;i<k;i++)
		lc[i][u]=lc[i-1][lc[i-1][u]];
}


//amount of gold
int qt[312345];
//cost of gold
int ct[312345];
//in hld
bool it[312345];
int pai[312345];
int mpt[312345];


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q;
	cin>>q;
	cin>>qt[0]>>ct[0];
	for(int i=1;i<=q;i++){
		int id;
		cin>>id;
		if(id==1){
			int pi;
			cin>>pi>>qt[i]>>ct[i];
			are[pi].pb(n);
			pai[i]=pi;
			lca_dfs(i,pi);
			//cout<<"Adiciona vrtice "<<i<<" com pai "<<pi<<endl;
		}
		else{
			int v,w;
			cin>>v>>w;
			//cout<<"O vrtice "<<v<<" compra "<<w<<endl;
			int wor=w,cost=0;
			while(w>0){
				int id=0,val=ct[0];
				int u=v;
				for(int i=k-1;i>=0;i--){
					if(qt[lc[i][u]]>0)u=lc[i][u];
				}
				//cout<<"Achou vrtice "<<u<<endl;
				if(qt[u]==0)break;
				else{
					int compra=min(w,qt[u]);
					w-=compra;
					qt[u]-=compra;
					cost+=compra*ct[u];
					//cout<<"Decide comprar "<<compra<<" de "<<id<<endl;
				}
			}
			cout<<wor-w<<" "<<cost<<endl;
		}
	}
	


}