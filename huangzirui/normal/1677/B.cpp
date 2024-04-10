#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1000010;
int i,j,k,n,m,T,sum[maxn],sum2[maxn];
string S;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		cin>>S;
		for(i=1;i<=S.size();i++)
			sum[i]=sum[i-1]+(S[i-1]=='1');
		for(i=1;i<=S.size();i++)
			sum2[i]=(i>=m?sum2[i-m]:0)+(S[i-1]=='1');
		for(i=S.size();i>=1;i--)
			sum[i]-=(i>=m?sum[i-m]:0),sum[i]=min(sum[i],1);
		for(i=S.size();i>=1;i--)
			sum2[i]=min(sum2[i],1);
		for(i=1;i<=S.size();i++)
			sum[i]+=(i>=m?sum[i-m]:0);
		for(i=1;i<=S.size();i++)
			sum2[i]+=sum2[i-1];
		for(i=S.size();i>=1;i--)
			sum2[i]-=(i>=m?sum2[i-m]:0);
		for(i=1;i<=n*m;i++){
			printf("%d ",sum[i]+sum2[i]);
		}puts("");
	}
	return 0;
}
//0000000011001101