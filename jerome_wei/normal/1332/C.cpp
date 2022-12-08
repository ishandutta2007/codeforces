#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,k;
char s[N];

int cnt[26];
bool vis[N];

inline void dfs(int x){
	cnt[s[x]-'a']++;
	vis[x]=1;
	int nxt1=n+1-x;
	int nxt2=(x+k>=n)?x:x+k;
	int nxt3=(x-k<=0)?x:x-k;
	if(!vis[nxt1])dfs(nxt1);
	if(!vis[nxt2])dfs(nxt2);
	if(!vis[nxt3])dfs(nxt3);
}

int main()
{
	int T;cin >> T;
	while(T--){
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		int ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				memset(cnt,0,sizeof(cnt));
				dfs(i);
				int mx=0;
				for(int i=0;i<26;i++){
					ans+=cnt[i];
					mx=max(mx,cnt[i]);
				}
				ans-=mx;
			}
		}
		printf("%d\n",ans);
	}
}