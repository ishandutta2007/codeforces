#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a,b,c,d;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		b-=a;
		if(b%(c+d)){
			cout<<-1<<'\n';
		}
		else{
			cout<<b/(c+d)<<'\n';
		}
	}
}