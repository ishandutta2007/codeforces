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
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
const int maxn=125;
ll f[maxn][maxn];
int main(){
    int T;
	T=read();
	while(T--){
		ll t;int x,y;
		t=read();x=read();y=read();t-=x+y;
		if(t<0){puts("NO");continue;}
		memset(f,0,sizeof(f));
		f[0][0]=t;
		for(int i=0;i<120;i++)
			for(int j=0;j<120;j++)
				f[i][j+1]+=(f[i][j]+1)/2,f[i+1][j]+=f[i][j]/2;
		int p=0,q=0;
		while(p+q<x+y){
			if(p>=120||q>=120)break;
			if(f[p][q]&1)p++;else q++;
		}
		if(p==x&&q==y)puts("YES");else puts("NO");
	}
    return 0;
}