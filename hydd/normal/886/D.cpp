#include<bits/stdc++.h>
using namespace std;
int n,pre[110000],nxt[110000];
bool vis[110000]; string s;
int main(){
	cin>>n;
	memset(pre,-1,sizeof(pre));
	memset(nxt,-1,sizeof(nxt));
	while (n--){
		cin>>s; vis[s[0]-'a']=true;
		for (int i=1;i<(int)s.size();i++){
			int u=s[i-1]-'a',v=s[i]-'a';
			vis[v]=true;
			if (nxt[u]!=-1&&nxt[u]!=v||pre[v]!=-1&&pre[v]!=u){
				puts("NO");
				return 0;
			}
			nxt[u]=v; pre[v]=u;
		}
	}
	int tot=0; s.clear();
	for (int i=0;i<26;i++){
		tot+=vis[i];
		if (vis[i]&&pre[i]==-1){
			int u=i;
			while (u!=-1){
				tot--;
				s+=char(u+'a');
				u=nxt[u];
			}
		}
	}
	if (tot) puts("NO");
	else cout<<s<<endl;
	return 0;
}