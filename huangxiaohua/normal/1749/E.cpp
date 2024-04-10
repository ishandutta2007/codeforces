#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
vector<vector<int> >f;
vector<vector<pair<int,int> > >fa;
string s[400500];
vector<pair<int,int> >d={{0,1},{0,-1},{1,0},{-1,0}},d2={{1,1},{1,-1},{-1,1},{-1,-1}},res;

int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	for(i=1;i<=n;i++){
    		cin>>s[i];
    		s[i]="#"+s[i]+"#";
		}
		f=vector<vector<int> >(n+2,vector<int>(m+2,0));
		fa=vector<vector<pair<int,int>>>(n+2,vector<pair<int,int>>(m+2));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(s[i][j]=='.')for(auto [dx,dy]:d){
					dx+=i;dy+=j;
					if(dy<1||dy>m||dx<1||dx>n)continue;
					if(s[dx][dy]=='#'){
						f[i][j]=1;break;
					}
				}
			}
		}
		deque<tuple<int,int,int,int> >q;
		for(i=1;i<=n;i++)q.push_back({i,0,-1,-1});
		f[1][0]=0;
		res.clear();
		while(!q.empty()){
			auto [x,y,fx,fy]=q.front();q.pop_front();
			if(f[x][y])continue;
			f[x][y]=1;
			fa[x][y]={fx,fy};
			if(y>m)break;
			for(auto [dx,dy]:d2){
				dx+=x;dy+=y;
				if(dx<1||dx>n)continue;
				if(f[dx][dy])continue;
				if(s[dx][dy]=='#')q.push_front({dx,dy,x,y});
				else q.push_back({dx,dy,x,y});
			}
		}
		for(i=1;i<=n;i++){
			if(f[i][m+1]){
				j=m+1;
				while(i!=-1){
					s[i][j]='#';
					auto [x,y]=fa[i][j];
					i=x;j=y;
				}
				cout<<"YES\n";
				for(i=1;i<=n;i++)cout<<s[i].substr(1,m)<<'\n';
				goto aaa;
			}
		}
		cout<<"NO\n";
		aaa:;
	}
}