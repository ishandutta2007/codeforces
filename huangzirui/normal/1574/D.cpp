#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=11,maxm=200010;
struct chs{
	int is[maxn];
}st,W[maxm];
int i,j,k,n,m,T,a[maxn][maxm];
bool operator<(chs x,chs y){
	for(int i=1;i<=n;i++)if(x.is[i]<y.is[i])return true;else if(x.is[i]>y.is[i])return false;
	return false;
}
priority_queue<pair<int,chs>>Q;
map<chs,bool>M,M2;
int main(){
	srand(time(0));
	cin>>n;
	int w=0;
	for(i=1;i<=n;i++){
		int c=read();
		for(j=1;j<=c;j++)a[i][j]=read();
		w+=a[i][c];
		st.is[i]=c;
	}
	cin>>m;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)W[i].is[j]=read();
		M[W[i]]=1;
	}
	Q.push(make_pair(w,st));
	M2[st]=1;
	chs u,now;
	while(!Q.empty()){
		now=Q.top().second;
		int w=Q.top().first;
		if(!M[now]){
			for(i=1;i<=n;i++)printf("%d ",now.is[i]);
			puts("");exit(0);
		}
		Q.pop();
		for(i=1;i<=n;i++){
			if(now.is[i]==1)continue;
			u=now;int sum=w-(a[i][now.is[i]]-a[i][now.is[i]-1]);
			u.is[i]--;
			if(M2[u])continue;
			Q.push(make_pair(sum,u));
			M2[u]=1;
		}
	}
	return 0;
}