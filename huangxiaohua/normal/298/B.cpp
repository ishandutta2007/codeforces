#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y;
char s[100500];

int main(){
	ios::sync_with_stdio(0);
	int x1,y1,x2,y2;
	cin>>n>>x1>>y1>>x2>>y2>>s+1;
	x1-=x2;y1-=y2;
	if(!x2&&!y2){
		cout<<i;return 0;
	}
	for(i=1;i<=n;i++){
		if(s[i]=='E'){
			if(x1<0)x1++;
		}
		if(s[i]=='W'){
			if(x1>0)x1--;
		}
		if(s[i]=='N'){
			if(y1<0)y1++;
		}
		if(s[i]=='S'){
			if(y1>0)y1--;
		}
		//printf("NMSL%d %d %d\n",i,x1,y1);
		if(!x1&&!y1){
			cout<<i;return 0;
		}
	}
	cout<<-1;
}