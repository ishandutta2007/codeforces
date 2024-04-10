#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,fa[1005000],b[1005000],r[1005000],x,y,sb;
set<pair<int,int> > s;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

int main(){
    scanf("%d",&n);
	sb=n-1;
    for(i=1;i<=n;i++){
    	scanf("%d%d",&x,&y);
    	b[x]=b[y]=i;
    	r[x]=y;r[y]=-y;
    	fa[i]=i;
	}
	for(i=1;i<=n+n;i++){
		if(r[i]<0){
			s.erase({i,b[i]});
		}
		else{
			for(auto [x,y]:s){
				if(x>=r[i]){break;}m++;
				if(find(y)!=find(b[i])){sb--;}
				fa[fa[y]]=fa[b[i]];
			}
			if(m>n-1){puts("NO");return 0;}
			s.insert({r[i],b[i]});
		}
	}
	puts((m!=n-1||sb)?"NO":"YES");
}