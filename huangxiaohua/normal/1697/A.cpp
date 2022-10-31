#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		while(n--){
			cin>>k;m-=k;
		}
		if(m>=0)cout<<"0\n";
		else cout<<-m<<'\n';
	}
}