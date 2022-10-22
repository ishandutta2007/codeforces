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
int s[maxn],a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
	T=read();
	while(T--){
		int n,k;
		n=read();k=read();
		for(int i=1;i<=k;i++)s[i]=read();
		if(k==1){puts("YES");continue;}
		for(int i=2;i<=k;i++)a[i]=s[i]-s[i-1];
		bool tag=0;
		for(int i=3;i<=k;i++)if(a[i]<a[i-1])tag=1;
		if(tag){puts("NO");continue;}
		int v=s[1]/(n-k+1),w;
		if(s[1]-v*(n-k+1)==0)w=v;else if(s[1]<0)w=v;else w=v+1;
		if(a[2]<w)puts("NO");else puts("YES");
	}
    return 0;
}