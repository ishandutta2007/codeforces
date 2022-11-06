#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline char smax(int&x,const int&y){return x<y?x=y,1:0;}
inline char smin(int&x,const int&y){return x>y?x=y,1:0;}
int main(){
	int x,y;cin>>y>>x;
	int a[3]={x,x,x},ans=0;
	while(a[0]!=y){
		if(a[1]+a[2]-1<=y)a[0]=a[1]+a[2]-1;
		else a[0]=y;sort(a,a+3);++ans;
	}
	cout<<ans;
	return 0;
}