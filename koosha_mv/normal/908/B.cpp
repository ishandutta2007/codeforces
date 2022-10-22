#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int d[4]={0,1,2,3},dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}},ans=0,n,m;
int i,j,k;
char s[1001][1001];
char t[1001];

int main(){
	scanf("%d%d",&n,&m);
	int sx=-1, sy=-1;
	int ex=-1, ey=-1;
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
		for(j=0;j<m;j++){
			if(s[i][j]=='S') sx=i, sy=j;
			if(s[i][j]=='E') ex=i, ey=j;
		}
	}
	scanf("%s",t);
	do {
		int x=sx, y=sy;
		for(i=0;t[i];i++){
			x+=dir[d[t[i]-'0']][0];
			y+=dir[d[t[i]-'0']][1];
			if(x<0||y<0||x>=n||y>=m||s[x][y]=='E'||s[x][y]=='#'){
				break;
			}
		}
		
		if(s[x][y]=='E') ans++;
	} while(std::next_permutation(d,d+4));
 
	printf("%d\n",ans);
}