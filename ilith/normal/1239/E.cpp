#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=1.5e6+7;
int n,m,s[N],su,ans,x,f[51][N];
bool b[51][N];
signed main(){
	scanf("%d",&n),m=n*2,**b=1;
	FOR(i,1,m)scanf("%d",s+i);
	sort(s+1,s+m+1),ans=s[1]+s[2];
	ROF(i,m,3){
		su+=s[i];
		ROF(k,m-i+1,1)ROF(j,su,s[i]){
			if(!b[k][j]&&b[k-1][j-s[i]])b[k][j]=1,f[k][j]=i;
		}
	}
	ROF(S,su/2,0)if(b[n-1][S]){
		printf("%d ",s[1]);
		ROF(i,n-1,1)x=f[i][S],S-=s[x],printf("%d ",s[x]),s[x]=-1;
		puts("");
		ROF(i,m,3)if(~s[i])printf("%d ",s[i]);
		return printf("%d",s[2]),0;
	}
	return 0;
}