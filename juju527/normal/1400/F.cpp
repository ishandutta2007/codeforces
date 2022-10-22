//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1005,maxt=1e4+5;
int n,x;
char s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int tmp[25];
int tot,t[maxt][9],fail[maxt];
bool ban[maxt];
void chk(int len){
	for(int i=1;i<=len;i++){
		int sum=0;
		for(int j=i;j<=len;j++){
			sum+=tmp[j];
			if(sum!=x&&x%sum==0)return ;
		}
	}
	int k=0;
	for(int i=1;i<=len;i++){
		int c=tmp[i]-1;
		if(!t[k][c])t[k][c]=++tot;
		k=t[k][c];
	}
	ban[k]=1;
	return ;
}
void dfs(int len,int sum){
	if(sum==x){chk(len);return ;}
	for(int i=1;i<=9;i++){
		if(sum+i>x)return ;
		tmp[len+1]=i;
		dfs(len+1,sum+i);
	}
}
queue<int> q;
void init(){
	for(int i=0;i<9;i++)if(t[0][i])q.push(t[0][i]);
	while(q.size()){
		int k=q.front();
		q.pop();
		for(int i=0;i<9;i++){
			int tmp=t[k][i];
			if(tmp)fail[tmp]=t[fail[k]][i],q.push(tmp);
			else t[k][i]=t[fail[k]][i];
		}
	}
}
int f[maxn][maxt];
inline void trans(int &x,int y){x=max(x,y);return ;}
int main(){
    scanf("%s",s+1);n=strlen(s+1);
	x=read();dfs(0,0);init();
	for(int i=0;i<n;i++){
		int c=s[i+1]-'1';
		for(int j=0;j<=tot;j++){
			trans(f[i+1][j],f[i][j]);
			if(!ban[t[j][c]])trans(f[i+1][t[j][c]],f[i][j]+1);
		}
	}
	int res=0;
	for(int i=0;i<=tot;i++)res=max(res,f[n][i]);
	printf("%d\n",n-res);
    return 0;
}