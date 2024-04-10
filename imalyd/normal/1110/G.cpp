#include<bits/stdc++.h>
using namespace std;
#define ll long long
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
const int N=2000005;
int t,n,m,d[N];
char c[N];
vector<int>e[N];
void add(int v,int u){e[v].push_back(u);e[u].push_back(v);}
void app(int v){e[++n].clear();add(v,n);}
int ac(){
	int v=0;
	for(int i=1;i<=n;i++)if(d[i]>3)return 4;
	for(int i=1;i<=n;i++)if(d[i]>2){
		++v;int x=0;
		for(int j=0;j<d[i];j++)if(d[e[i][j]]!=1)++x;
		if(x>1)return 3;
	}
	if(v>2)return 2;
	return v==2&&(n&1);
}
int main(){
	t=rd();
	while(t--){
	    m=n=rd();
	    for(int i=1;i<=n;i++)e[i].clear();
	    for(int i=1;i<n;i++)add(rd(),rd());
	    scanf("%s",c+1);
	    for(int i=1;i<=m;i++)if(c[i]=='W'){app(i);int v=n;app(v);app(v);}
		for(int i=1;i<=n;i++)d[i]=(int)e[i].size();
	    /*for(int i=1;i<=n;i++){
	        printf("node %d:",i);
	        for(int j=0;j<d[i];j++)printf(" %d",e[i][j]);printf("\n");
	    }
		printf("\n");*/
		if(ac())puts("White");else puts("Draw");
	}
	return 0;
}