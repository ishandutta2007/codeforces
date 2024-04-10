#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,fa[3005000],t1,t2,mn[3000500],nmsl[500500];
int p1[500500],p2[500500],l[500500],r[500500],res[500500];
string s[66];
int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
vector<pair<int,int> >q[500500];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(i=0;i<=3000000;i++){
		fa[i]=i;
		mn[i]=1e9;
	}
	cin>>n;
	for(i=1;i<=3;i++){
		cin>>s[i];
		s[i]="0"+s[i];
		for(auto &j:s[i]){
			j-='0';
		}
	}
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>j>>k;
		q[k].push_back({i,j});
	}
	for(i=1;i<=n;i++){
		if(s[1][i]&&s[3][i]){
			if(l[i-1])l[i]=l[i-1];
			else l[i]=i;
		}
	}
	for(i=n;i>=1;i--){
		if(s[1][i]&&s[3][i]){
			if(r[i+1])r[i]=r[i+1];
			else r[i]=i;
		}
		for(j=1;j<=3;j++){
			mn[find(i*3+j)]=i;
		}
	}
	for(i=1;i<=n;i++){
		p1[i]=p1[i-1];
		for(j=1;j<=3;j++){
			if(!s[j][i])continue;
			p1[i]++;
			if(j>1&&s[j-1][i]){
				if(find(j-1+i*3)!=find(j+i*3)){
					mn[find(j-1+i*3)]=min(mn[find(j+i*3)],mn[find(j-1+i*3)]);
					fa[find(j+i*3)]=find(j-1+i*3);
					p1[i]--;
				}
			}
			if(i>1&&s[j][i-1]){
				if(find(j-3+i*3)!=find(j+i*3)){
					mn[find(j-3+i*3)]=min(mn[find(j+i*3)],mn[find(j-3+i*3)]);
					fa[find(j+i*3)]=find(j-3+i*3);
					p1[i]--;
				}
			}
		}
		//cout<<p1[i]<<endl;
		p2[i]=p2[i-1];
		if(s[1][i]&&s[2][i]&&s[3][i]){
			p2[i]++;
		}
		
		if(s[1][i]&&s[3][i]&&find(i*3+1)!=find(i*3+3)){
			nmsl[i]=1;
		}
		
		/////////////////////////////
		for(auto [id,i1]:q[i]){
			int x,y;
			x=i1;y=i;
			if(x==y){
				res[id]=s[1][x]+s[2][x]+s[3][x];
				if(s[1][x]&&s[2][x])res[id]--;
				if(s[3][x]&&s[2][x])res[id]--;
			}
			else{
				set<int> sb;
				for(int i=1;i<=3;i++){
					if(s[i][x]&&mn[find(x*3+i)]<x){
						sb.insert(find(x*3+i));
					}
				}
				//printf("NMSL%d %d %d\n",x,y,sb.size());
				res[id]=p1[y]-p1[x-1]+sb.size();
				if(nmsl[x-1]){
					t2=( p2[ min(y,r[x-1]) ] - p2[ x-1-1 ] );
					if(t2)res[id]++;
				}
				
				if(s[1][x]&&!s[2][x]&&s[3][x]){
					t1=( p2[ x ] - p2[ l[x]-1 ] );
					t2=( p2[ min(r[x],y) ] - p2[ x-1 ] );
					if(t1&&!t2)res[id]++;
				}
				
			}
		}
	}
	for(i=1;i<=t;i++)cout<<res[i]<<'\n';
}