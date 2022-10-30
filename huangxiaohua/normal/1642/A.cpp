#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		if(b==d&&b>f){
			cout<<abs(a-c)<<endl;continue;
		}
		if(b==f&&b>d){
			cout<<abs(a-e)<<endl;continue;
		}
		if(d==f&&d>b){
			cout<<abs(c-e)<<endl;continue;
		}
		cout<<0<<endl;
	}
}