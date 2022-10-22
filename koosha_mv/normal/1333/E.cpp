#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=501;
const int d[4][4]={{4,5,6,7},
						{3,14,16,8},
						{2,13,9,10},
						{1,15,12,11}};
int n,m[N][N],cnt=1,k,x,y;
void dr(int xx,int yy,int t){
	x=xx,y=yy;
	while(x<=xx+t)
		m[x++][y]=cnt++;
	x--,y++;
	while(y<=yy+t)
		m[x][y++]=cnt++;
	y--,x--;
	while(x>=xx)
		m[x--][y]=cnt++;
	x++,y--;
	while(y>yy){
		m[x][y--]=cnt++;
	}
}
void solve1(int x,int y){
	cnt--;
	m[x][y]=cnt+1,m[x][y+1]=cnt+3,m[x][y+2]=cnt+4;
	m[x+1][y]=cnt+9,m[x+1][y+1]=cnt+2,m[x+1][y+2]=cnt+5;
	m[x+2][y]=cnt+7,m[x+2][y+1]=cnt+6,m[x+2][y+2]=cnt+8;
}
void solve2(int x,int y){
	cnt--;
	f(i,0,4)
		f(j,0,4)
			m[x+i][y+j]=cnt+d[i][j];
}
int main(){
	cin>>n;
	if(n<=2) return cout<<-1,0;
	if(n%2){
		f(i,0,n/2-1)
			dr(i,i,n-1-(i*2));
		solve1(n/2-1,n/2-1);
	}
	else{
		f(i,0,n/2-2)
			dr(i,i,n-1-(i*2));
		solve2(n/2-2,n/2-2);
	}
	f(i,0,n){
		f(j,0,n)
			printf("%d%s",m[i][j]," ");
		printf("\n");
	}		
}