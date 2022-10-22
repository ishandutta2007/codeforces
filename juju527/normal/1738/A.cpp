//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vec c[2];
int main(){
    int T;
	T=read();
	while(T--){
		int n;ll res=0;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		c[0].clear();c[1].clear();
		for(int i=1;i<=n;i++)c[a[i]].eb(b[i]);
		sort(c[0].begin(),c[0].end());
		sort(c[1].begin(),c[1].end());
		ll sum0=0,sum1=0;
		for(auto x:c[0])sum0+=x;
		for(auto x:c[1])sum1+=x;
		if(c[0].size()==c[1].size())res=(sum0+sum1)*2-min(c[0][0],c[1][0]);
		else{
			if(c[0].size()>c[1].size())swap(c[0],c[1]);
			int d=c[1].size()-c[0].size();
			ll aux=0;
			for(int i=0;i<d;i++)aux+=c[1][i];
			res=(sum0+sum1)*2-aux;
		}
		printf("%lld\n",res);
	}
    return 0;
}