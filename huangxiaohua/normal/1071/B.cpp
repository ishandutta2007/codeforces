#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,f[2050][2050],mx;

char s[2050][2050],mn;
bool vis[2050][2050];
string res;
vector<pair<int,int> >v,v2;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s[i]+1;
	}
	memset(f,1,sizeof(f));
	f[1][0]=0;
	for(x=1;x<=n;x++){
		for(y=1;y<=n;y++){
			f[x][y]=min(f[x-1][y],f[x][y-1]);
			f[x][y]+=(s[x][y]!='a');
		}
	}
	if(f[n][n]<=m){
		for(i=1;i<n+n;i++){
			cout<<'a';
		}return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			//printf("a%d %d %d\n",i,j,f[i][j]);
			if(f[i][j]<=m){
				mx=max(mx,i+j);
			}
		}
	}
	//cout<<mx;
	for(i=1;i<mx;i++){
		res+="a";
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if((i+j)==mx&&f[i][j]<=m){
				//printf("%d %d\n",i,j);
				v.push_back({i,j});
			}
		}
	}
	if(!mx){
		v.push_back({0,1});
	}
	while(!v.empty()){
		mn='z'+1;
		for(auto [i,j]:v){
			i++;
			if(i<=n&&j<=n&&i>=1&&j>=1){
				mn=min(mn,s[i][j]);
			}
			i--;j++;
			if(i<=n&&j<=n&&i>=1&&j>=1){
				mn=min(mn,s[i][j]);
			}
		}
		if(mn>'z')break;
		res+=mn;
		for(auto [i,j]:v){
			i++;
			if(!vis[i][j]&&i<=n&&j<=n&&i>=1&&j>=1&&s[i][j]==mn){
				vis[i][j]=1;
				v2.push_back({i,j});
			}
			i--;j++;
			if(!vis[i][j]&&i<=n&&j<=n&&i>=1&&j>=1&&s[i][j]==mn){
				vis[i][j]=1;
				v2.push_back({i,j});
			}
		}
		swap(v,v2);
		v2.clear();
	}
	cout<<res;
}