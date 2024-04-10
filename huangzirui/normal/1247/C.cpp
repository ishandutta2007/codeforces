#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll i,j,k,n,m;
void read(int &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
void read(ll &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
bool check(ll x,ll S){
	int num=0,X=x;
	while(x){
		if(x&1)++num;
		x>>=1;
	}
	if(S>=num && S<=X)return true;
	return false;
}
int main() {
	cin>>n>>m;
	while(!check(n,k)){
		++k;
		n-=m;
		if(m==0 && k>n){
			cout<<-1<<endl;
			return 0;
		}
		if(n<0){
			cout<<-1<<endl;
			return 0;
		}
	}cout<<k<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}