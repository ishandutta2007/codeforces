#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,lst,res;
string s0,s;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s0>>s;
		s+=s;s+=s;
		reverse(s.begin(),s.end());
		if(s0[0]=='g'){
			cout<<0<<'\n';continue;
		}
		res=0;lst=j=0;
		for(auto i:s){
			j++;
			if(i=='g'){
				lst=j;
			}
			else if(i==s0[0]){
				res=max(res,j-lst);
			}
		}
		cout<<res<<'\n';
	}
}