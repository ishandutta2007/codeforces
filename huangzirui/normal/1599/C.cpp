#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=1010;
int i,j,k,n,m,T;double p;
ll C(int x,int y){
	if(y==3)return 1ll*x*(x-1)/2*(x-2)/3;
	if(y==2)return 1ll*x*(x-1)/2;
	if(y==1)return 1ll*x;
	if(!y)return 1ll;
}
double check(int c){
	double ans=0;
	ans+=(C(c,3)+C(c,2)*(n-c)+C(c,1)*C(n-c,2)*0.5)/C(n,3);
	//cout<<"c="<<c<<' '<<ans<<endl;
	return ans;
}
int main(){
	cin>>n>>p;
	for(int c=0;c<=n;c++){
		if(check(c)+1e-7>=p){cout<<c<<endl;return 0;}
	}
}