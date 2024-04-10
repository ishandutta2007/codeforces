#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,fa[200500],s[200500],it,g[200500],x,y;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		string s1;
		cin>>n>>s1;n*=2;
		for(i=1;i<=n;i++){
			fa[i]=i;
			s[i]=g[i]=0;
		}
		res=n;
		j=0;it=0;
		for(auto i:s1){
			j++;
			if(i=='('){
				s[++it]=j;
			}
			else{
				if(it){
					x=find(s[it]),y=find(j);
					if(x!=y){
						res--;fa[x]=y;
					}
					if(g[it]){
						x=find(g[it]),y=find(j);
						if(x!=y){
							res--;fa[x]=y;
						}
					}
					g[it]=s[it];g[it+1]=0;
					it--;
					
				}
				else {
					s[1]=s[0]=0;
					g[1]=g[0]=0;
				}
			}
		}
		cout<<res<<'\n';
	}
}