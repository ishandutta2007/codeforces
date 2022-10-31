#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	set<int> s1,s2;
    	for(i=1;i<=m;i++){
    		cin>>j>>k;
    		s1.insert(j);
    		s2.insert(k);
		}
		if(m==n){
			if(s1.size()!=m-1||s2.size()!=m-1){
				cout<<"NO\n";
			}
			else{
				cout<<"YES\n";
			}
			continue;
		}
		else{
			if(s1.size()<m-1||s2.size()<m-1){
				cout<<"NO\n";
			}
			else{
				cout<<"YES\n";
			}
			continue;
		}
	}
}