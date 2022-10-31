#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
char s[1005][1005];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>s[i]+1;
		}
		if(m%2){
			cout<<"YES"<<endl;
			for(i=1;i<=m+1;i++){
				cout<<i%2+1<<' ';
			}cout<<endl;
			continue;
		}
		if(n==2){
			if(s[1][2]==s[2][1]){
				cout<<"YES"<<endl;
				for(i=1;i<=m+1;i++){
					cout<<i%2+1<<' ';
				}cout<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			continue;
		}
		cout<<"YES"<<endl;
		if(s[1][2]==s[2][3]){
			for(i=1;i<=m/2;i++){
				cout<<((i-m/2)%3+3)%3+1<<' ';
			}
			cout<<2<<' ';
			for(i=1;i<=m/2;i++){
				cout<<(i+1)%3+1<<' ';
			}cout<<endl;continue;
		}
		if(s[2][3]==s[3][1]){
			for(i=1;i<=m/2;i++){
				cout<<((i-m/2+1)%3+3)%3+1<<' ';
			}
			cout<<3<<' ';
			for(i=1;i<=m/2;i++){
				cout<<(i+2)%3+1<<' ';
			}cout<<endl;continue;
		}
		if(s[3][1]==s[1][2]){
			for(i=1;i<=m/2;i++){
				cout<<((i-m/2+2)%3+3)%3+1<<' ';
			}
			cout<<1<<' ';
			for(i=1;i<=m/2;i++){
				cout<<(i+3)%3+1<<' ';
			}cout<<endl;continue;
		}
	}
}