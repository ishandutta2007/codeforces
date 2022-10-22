#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)									
#define minm(a,b) a=min(a,b);

const int N=4e5+99;

int n,m,q,x,y,ans=1,Fen[2][N];

void update(int x,int val,int s){ if(s) x=n+1-x,val=m+1-val; x++; while(x<=N){ minm(Fen[s][x],val); x+=(x&-x); } }
int Get(int x,int s){if(s) x=n+1-x; x++; int res=N; while(x>0){ minm(res,Fen[s][x]); x-=(x&-x); } if(s) return m+1-res; return res;} 

void do_it(int x,int y){
	int s=(x-1)%2;
	x=(x+1)/2,y=(y+1)/2;
	update(x,y,s);
	if(Get(x,0)-1<Get(x,1)) ans=0;
}

int main(){
	f(i,0,N) Fen[0][i]=Fen[1][i]=N;
	cin>>n>>m>>q;
	f(io,0,q){
		Gett(x,y);
		do_it(x,y);
		printf("%s\n",ans ? "YES":"NO");
	}
}