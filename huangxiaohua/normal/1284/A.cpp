#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s1[66],s2[66],res;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>s1[i];
	}
	for(i=0;i<m;i++){
		cin>>s2[i];
	}
	cin>>t;
	while(t--){
		cin>>k;k--;
		res=s1[k%n]+s2[k%m];
		cout<<res<<endl;
	}
}