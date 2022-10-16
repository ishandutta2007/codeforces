#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
int n,m,T,i,x[5],y[5],xx,yy,j,k,a[N],b[N];
char ch;
string s;
ll l,r;
bool c(int a,int b){
	int f1=(abs(x[0]-a)+abs(x[1]-a)+abs(x[2]-a)+
	abs(y[0]-b)+abs(y[1]-b)+abs(y[2]-b));
	if(f1!=2)return 0;
	if(min(abs(a-xx),abs(b-yy))==0)return 1;
	else return max(min(a,n+1-a),min(b,n+1-b))!=1&&(((xx-a)&(yy-b))&1)==0;
}
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n;
		cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]>>xx>>yy;
		if(c(x[0],y[0])||c(x[1],y[1])||c(x[2],y[2]))cout<<"YES\n";
		else cout<<"NO\n";
	}
}