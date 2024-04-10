#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,it;
char c;
string s[105],sb[105],ans[105];
bool vis[105][105],no[105][105];
map<string,int> mp;

int rd0(){
	int res=0;char c;
	while(1){
		c=getchar();
		if(c=='\n')return res;
		if(c>='0'&&c<='9')res=res*10+c-'0';
	}
}

void rd(int x){
	char c;
	string tmp;
	while(1){
		c=getchar();
		if(c=='\n'){
			s[x]=s[x]+tmp;return;
		}
		if(c==':'){
			if(tmp[0]!='?')ans[x]=tmp;
			tmp.clear();s[x]+=":";continue;
		}
		else if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z')||c==':'||c=='?'||c=='.'||c=='!'||c==','||c==' ')tmp+=c;
	}
}

void chk(int x){
	int i,j,k,len=s[x].size(),m;
	string tmp;
	for(i=1;i<=n;i++){
		m=sb[i].size();
		
		//cout<<s[x]<<endl;
		for(j=0;j+m-1<len;j++){
			tmp=s[x].substr(j,m);
			//cout<<tmp<<endl;
			if(tmp==sb[i]){
				if(j&&(s[x][j-1]!='?'&&s[x][j-1]!=':'&&s[x][j-1]!='.'&&s[x][j-1]!='!'&&s[x][j-1]!=','&&s[x][j-1]!=' ')){
					//cout<<"NMSL";
					continue;
				}
				if(j+m<=len-1 &&(s[x][j+m]!='?'&&s[x][j+m]!=':'&&s[x][j+m]!='.'&&s[x][j+m]!='!'&&s[x][j+m]!=','&&s[x][j+m]!=' '))continue;
				no[x][i]=1;break;
			}
		}
	}
}

bool dfs(int x,int y){
	if(vis[x][y])return 0;
	ans[x]=sb[y];
	vis[x][y]=1;
	if(x==m)return 1;
	if(!ans[x+1].empty()){
		if(mp[ans[x+1]]==y||!dfs(x+1,mp[ans[x+1]])){
			ans[x]="";return 0;
		}
		return 1;
	}
	for(int i=1;i<=n;i++){
		if(!no[x+1][i]&&i!=y){
			if(dfs(x+1,i))return 1;
		}
	}
	ans[x]="";
	return 0;
}

int main() {
	cin.tie(0);
	t=rd0();
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(no,0,sizeof(no));
		n=rd0();it=0;
		char c;string tmp;
		mp.clear();
		while(1){
			c=getchar();
			//cout<<c<<endl;
			if(c=='\n'){
				sb[++it]=tmp;mp[tmp]=it;break;
			}
			if(c==' '){
				sb[++it]=tmp;mp[tmp]=it;tmp.clear();
			}
			else if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))tmp+=c;
		}
		m=rd0();
		for(i=1;i<=m;i++){
			s[i].clear();
			ans[i].clear();
			rd(i);
			chk(i);
		}
		//for(i=1;i<=n;i++){cout<<i<<' '<<sb[i]<<'\n';}
		//for(i=1;i<=m;i++){cout<<i<<' '<<s[i]<<'\n'<<ans[i]<<'\n';}
		//for(i=1;i<=m;i++){for(j=1;j<=n;j++){cout<<no[i][j]<<' ';}cout<<endl;}
		if(dfs(0,0)){
			string tmp;
			for(i=1;i<=m;i++){
				tmp=ans[i]+s[i];
				cout<<tmp<<'\n';
			}
		}
		else cout<<"Impossible\n";
	}
}