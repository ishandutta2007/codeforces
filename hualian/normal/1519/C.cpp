#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int t;
int ans[200010];
int u[N];
vector<int>had[N];
signed main(){
	t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=n;i++)u[i]=read();
		for(int i=1;i<=n;i++){
			int x=read();
			had[u[i]].push_back(x);
		} 
		for(int i=1;i<=n;i++){
			sort(had[i].begin(),had[i].end());
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<had[i].size();j++){
				had[i][j]+=had[i][j-1];
			}
			for(int k=1;k<=had[i].size();k++){
				int len=had[i].size();
				if(len%k==0)ans[k]+=had[i][len-1];
				else ans[k]+=had[i][len-1]-had[i][len%k-1];
			}
			had[i].clear();
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
			ans[i]=0;
		}puts("");
	}
	return 0;
}