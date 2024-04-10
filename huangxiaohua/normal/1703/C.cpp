#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++){
			cin>>m>>s;
			for(auto j:s){
				if(j=='D')a[i]++;
				else a[i]+=9;
			}
			cout<<a[i]%10<<' ';
		}
		cout<<endl;
	}
}