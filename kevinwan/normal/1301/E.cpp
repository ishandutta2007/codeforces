#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=500+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int ms[mn][mn];
int val[mn][mn];
int sp[mn][mn][9][9];
string s[mn];
void init(int n,int m){
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)sp[i][j][0][0]=val[i][j];
	for(int k=1;k<9;k++)for(int i=0;i+(1<<k)<=n;i++)for(int j=0;j<m;j++)
		sp[i][j][k][0]=max(sp[i][j][k-1][0],sp[i+(1<<k-1)][j][k-1][0]);
	for(int l=1;l<9;l++)for(int k=0;k<9;k++)for(int i=0;i+(1<<k)<=n;i++)for(int j=0;j+(1<<l)<=m;j++)
		sp[i][j][k][l]=max(sp[i][j][k][l-1],sp[i][j+(1<<l-1)][k][l-1]);
}
int query(int a,int b,int c,int d){
	if(a>c||b>d)return 0;
	int k=31-__builtin_clz(c-a+1),l=31-__builtin_clz(d-b+1);
	return max(max(sp[a][b][k][l],sp[a][d-(1<<l)+1][k][l]),
		max(sp[c-(1<<k)+1][b][k][l],sp[c-(1<<k)+1][d-(1<<l)+1][k][l]));
}
int main(){
	#ifdef LOCAL_PROJECT
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#else
	cin.tie(0);
	cin.sync_with_stdio(0);
	#endif
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)cin>>s[i];
	memset(val,0x3f,sizeof(val));
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(!i||!j)ms[i][j]=(s[i][j]=='R');
		else ms[i][j]=(s[i][j]=='R')?(min(min(ms[i-1][j],ms[i][j-1]),ms[i-1][j-1])+1):0;
	}
	for(int i=0;i<n-1;i++)for(int j=0;j<m-1;j++)val[i][j]=min(val[i][j],ms[i][j]);
	for(int i=0;i<n;i++)for(int j=m-1;j>=0;j--){
		if(!i||j==m-1)ms[i][j]=(s[i][j]=='G');
		else ms[i][j]=(s[i][j]=='G')?(min(min(ms[i-1][j],ms[i][j+1]),ms[i-1][j+1])+1):0;
	}
	for(int i=0;i<n-1;i++)for(int j=0;j<m-1;j++)val[i][j]=min(val[i][j],ms[i][j+1]);
	for(int i=n-1;i>=0;i--)for(int j=0;j<m;j++){
		if(i==n-1||!j)ms[i][j]=(s[i][j]=='Y');
		else ms[i][j]=(s[i][j]=='Y')?(min(min(ms[i+1][j],ms[i][j-1]),ms[i+1][j-1])+1):0;
	}
	for(int i=0;i<n-1;i++)for(int j=0;j<m-1;j++)val[i][j]=min(val[i][j],ms[i+1][j]);
	for(int i=n-1;i>=0;i--)for(int j=m-1;j>=0;j--){
		if(i==n-1||j==m-1)ms[i][j]=(s[i][j]=='B');
		else ms[i][j]=(s[i][j]=='B')?(min(min(ms[i+1][j],ms[i][j+1]),ms[i+1][j+1])+1):0;
	}
	for(int i=0;i<n-1;i++)for(int j=0;j<m-1;j++)val[i][j]=min(val[i][j],ms[i+1][j+1]);
	init(n-1,m-1);
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		int cur=0;
		for(int i=256;i;i>>=1){
			int x=cur+i;
			if(query(a+x-1,b+x-1,c-x,d-x)>=x)cur+=i;
		}
		printf("%d\n",4*cur*cur);
	}
}