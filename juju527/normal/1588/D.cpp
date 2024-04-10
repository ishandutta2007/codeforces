#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=15,maxl=105,maxs=(1<<10)+5;
int n;
char s[maxl];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int len[maxn];
int pos[52][maxn][2];
int f[52][maxs];
pair<int,int> path[52][maxs];
struct node{
	int c,s;
	bool operator <(node x){
		int d=x.c,t=x.s;
		for(int i=0;i<n;i++){
			if(pos[c][i][(s>>i)&1]<pos[d][i][(t>>i)&1])return 1;
			else if(pos[c][i][(s>>i)&1]>pos[d][i][(t>>i)&1])return 0;
		}
	}
};
vector<node> st;
int ans[maxl];
int main(){
	int T;
	T=read();
	while(T--){
		int S;
		n=read();S=(1<<n)-1;
		for(int i=0;i<n;i++){
			int m;
			scanf("%s",s+1);len[i]=m=strlen(s+1);
			for(int c=0;c<52;c++)pos[c][i][0]=pos[c][i][1]=m+1;
			for(int j=1;j<=m;j++){
				int c=(s[j]>='a')?(s[j]-'a'+26):(s[j]-'A');
				if(pos[c][i][0]==m+1)pos[c][i][0]=j;
				else pos[c][i][1]=j;
			}
		}
		memset(f,0,sizeof(f));
		st.clear();
		int res=0,ch,ss;
		for(int c=0;c<52;c++){
			for(int s=0;s<=S;s++){
				bool tag=1;
				for(int i=0;i<n;i++)if(pos[c][i][(s>>i)&1]==len[i]+1)tag=0;
				if(!tag)continue;
				st.push_back((node){c,s});
				f[c][s]=1;ch=c,ss=s;
			}
		}
		sort(st.begin(),st.end());
		for(auto x:st){
			int c=x.c,s=x.s;
			if(res<f[c][s])ch=c,ss=s;
			res=max(res,f[c][s]);
			for(int d=0;d<52;d++){
				int t=0;
				bool tag=1;
				for(int i=0;i<n;i++){
					int x=pos[c][i][(s>>i)&1];
					if(pos[d][i][1]<=x){tag=0;break;}
					else if(pos[d][i][0]<=x)t|=(1<<i);
				}
				if(tag&&f[d][t]<f[c][s]+1)path[d][t]=make_pair(c,s),f[d][t]=f[c][s]+1;
			}
		}
		printf("%d\n",res);
		int len=res;
		while(res--){
			ans[res]=ch;
			int c=path[ch][ss].fi,s=path[ch][ss].se;
			ch=c,ss=s;
		}
		for(int i=0;i<len;i++)printf("%c",(ans[i]<26)?(ans[i]+'A'):(ans[i]-26+'a'));
		puts("");
	}
    return 0;
}