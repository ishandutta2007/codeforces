#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m;
void read(int &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
void read(ll &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
int main() {
	cin>>n>>m;
	if(n==9 && m==1){cout<<9<<' '<<10<<endl;return 0;}
	if(n==m){
		cout<<n*10<<' '<<m*10+1<<endl;
		return 0;
	}
	if(n==m-1){
		cout<<n<<9<<' '<<m<<0<<endl;
		return 0;
	}cout<<-1<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}