#include<bits/stdc++.h>
using namespace std;
string s; bool vis[1100000];
int cnt,pos[1100000];
int main(){
	cin>>s; int n=s.length(),tot=0;
	for (int i=0;i<n;i++)
		if (s[i]!=s[(i+1)%n]) tot++;
	if (tot==0) puts("1");
	else if (tot==n) printf("%d\n",(n>>1));
	else{
		for (int i=0;i<n;i++)
			if (s[i]==s[(i+1)%n]){
				vis[i]=true;
				vis[(i+1)%n]=true;
			}
		int ans=0;
		for (int i=0;i<n;i++){
			if (vis[i]&&!vis[(i+1)%n]) pos[++cnt]=(i+1)%n;
			if (vis[i]&&(s[i]!=s[(i+1)%n])) ans++;
		}
		for (int i=1;i<=cnt;i++){
			int x=pos[i],tot=0;
			while (!vis[x]) x=(x+1)%n,tot++;
			ans+=(tot>>1);
		}
		printf("%d\n",ans);
	}
	return 0;
}