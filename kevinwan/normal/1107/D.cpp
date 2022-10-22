#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll mod=(1LL<<61)-1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const lll mul=57497633;
const int mn=5200+10;
int b[mn][mn];
void rc(int r,int c){
	char _=getchar();
	while(_=='\n')_=getchar();
	int __=(_>='A')?(_-'A'+10):(_-'0');
	for(c+=3;__;__>>=1,c--)b[r][c]=__&1;
}
int rec(int a,int aa,int c,int d){
	return b[c][d]-(a?b[a-1][d]:0)-(aa?b[c][aa-1]:0)+((a*aa)?b[a-1][aa-1]:0);
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
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j+=4)rc(i,j);
    for(int i=1;i<n;i++)b[0][i]+=b[0][i-1],b[i][0]+=b[i-1][0];
    for(int i=1;i<n;i++)for(int j=1;j<n;j++)b[i][j]+=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)cerr<<rec(i,j,i,j)<<' ';cerr<<endl;}
    for(int i=n;i>=1;i--)if(n%i==0){
    	bool gud=1;
    	for(int j=0;j<n;j+=i)for(int k=0;k<n;k+=i){
    		int num=rec(j,k,j+i-1,k+i-1);
    		if(num!=0&&num!=i*i)gud=0;
    	}
    	if(gud){printf("%d\n",i);return 0;}
    }
}