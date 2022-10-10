#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=100010;
struct node{
	ll h,t;
}a[maxn];
bool cmp(node a,node b){return a.t<b.t;}
ll i,j,k,n,m,p,d[maxn],Q[maxn],sum[maxn],dp[maxn][110],l,r;
int main() {
	cin>>n>>m>>p;
	for(i=2;i<=n;i++)d[i]=read()+d[i-1];
	for(i=1;i<=m;i++)a[i]={read(),read()},a[i].t-=d[a[i].h];
	for(i=1;i<=m;i++)sum[i]=sum[i-1]+a[i].t;
	sort(a+1,a+1+m,cmp);
	//for(i=1;i<=m;i++)cout<<a[i].t<<' ';cout<<endl;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int h=1;h<=p;h++){
		Q[l=r=1]=0;
		for(i=1;i<=m;i++){
			while(r>l && (dp[Q[l]][h-1]-Q[l]*a[i].t+sum[Q[l]])>
						 (dp[Q[l+1]][h-1]-Q[l+1]*a[i].t+sum[Q[l+1]]))++l;
			dp[i][h]=dp[Q[l]][h-1]+a[i].t*(i-Q[l])-(sum[i]-sum[Q[l]]);
			//cout<<"dp "<<i<<' '<<h<<' '<<dp[i][h]<<' '<<Q[l]<<' '<<l<<' '<<r<<endl;
			while(r>l && (dp[Q[r]][h-1]+sum[Q[r]]-dp[Q[r-1]][h-1]-sum[Q[r-1]])/(Q[r]-Q[r-1])>
						 (dp[i][h-1]+sum[i]-dp[Q[r]][h-1]-sum[Q[r]])/(i-Q[r]))r--;
			Q[++r]=i;
		}
	}cout<<dp[m][p]<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}