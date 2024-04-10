#include <cstdio>
#include <iostream>
using namespace std;
#define int long long

int black,white,p,X1,X2,Y1,Y2,x1,x2,y1,y2,n,m,x3,y3,x4,y4;
void query(int x1,int y1,int x2,int y2,int x){
	int size=(x2-x1+1)*(y2-y1+1);
	if(x2-x1+1<=0||y2-y1+1<=0)return;
	black+=(size>>1)*x,white+=(size>>1)*x;
	if(size%2)
		if((x1+y1)%2==0)white+=x;
		else black+=x;
}
signed main(){
	scanf("%d",&p);
	for(int i=1;i<=p;i++){
		cin>>n>>m>>x1>>y1>>x2>>y2>>X1>>Y1>>X2>>Y2;
		black=white=0;
		query(1,1,n,m,1);
		query(x1,y1,x2,y2,-1);
		query(X1,Y1,X2,Y2,-1);
		white+=(x2-x1+1)*(y2-y1+1);
		black+=(X2-X1+1)*(Y2-Y1+1);
		x3=max(x1,X1);
		x4=min(x2,X2);
		y3=max(y1,Y1);
		y4=min(y2,Y2);
		query(x3,y3,x4,y4,1);
		int size=(x4-x3+1)*(y4-y3+1);
		if(x4-x3+1>0&&y4-y3+1>0)white-=size;
		cout<<white<<' '<<black<<endl;
	}
}