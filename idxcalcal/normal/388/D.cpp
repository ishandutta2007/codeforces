#include<bits/stdc++.h>
#define ri register int
#define pb push_back
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?0:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:0;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
int n,f[2][35][2],res=0,cur=0;
vector<bool>a;
int main(){
	cin>>n;
	while(n)a.pb(n&1),n>>=1;
	reverse(a.begin(),a.end());
	f[cur=0][0][1]=1;
	for(ri x,y,t=0;t<a.size();++t){
		cur^=1;
		memset(f[cur],0,sizeof(f[cur]));
		for(ri i=0;i<=a.size();++i){
			x=i?1<<(i-1):1,y=i?1<<(i-1):0;
			Add(f[cur][i][0],mul(f[!cur][i][0],1<<i));
			Add(f[cur][i+1][0],f[!cur][i][0]);
			if(a[t]){
				Add(f[cur][i][0],mul(f[!cur][i][1],x));
				Add(f[cur][i][1],mul(f[!cur][i][1],y));
				Add(f[cur][i+1][1],f[!cur][i][1]);
			}
			else Add(f[cur][i][1],mul(f[!cur][i][1],x));
		}
	}
	for(ri i=0;i<=a.size();++i)Add(res,add(f[cur][i][0],f[cur][i][1]));
	cout<<res;
	return 0;
}