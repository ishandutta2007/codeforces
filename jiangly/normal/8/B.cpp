#include<bits/stdc++.h>
using namespace std;
namespace obsession_with_robots{
	const int N=1e2;
	const char opt[]="LRUD";
	map<char,int>dx{{'L',-1},{'R',1},{'U',0},{'D',0}};
	map<char,int>dy{{'L',0},{'R',0},{'U',1},{'D',-1}};
	map<pair<int,int>,int>dis;
	int n;
	char a[N+1];
	void main(){
		scanf("%s",a);
		n=strlen(a);
		dis[{0,0}]=0;
		for(int i=0,x=0,y=0;i<n;++i){
			x+=dx[a[i]];
			y+=dy[a[i]];
			if(dis.count({x,y})){
				puts("BUG");
				return;
			}
			dis[{x,y}]=i+1;
			for(int j=0;j<=3;++j){
				int x1=x+dx[opt[j]],y1=y+dy[opt[j]];
				if(dis.count({x1,y1})&&dis[{x1,y1}]<i){
					puts("BUG");
					return;
				}
			}
		}
		puts("OK");
	}
}
int main(){
	obsession_with_robots::main();
	return 0;
}