#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int l,r;
int maxl;
int minr;
int main(){
	cin>>t;
	while(t--){
		minr=1000000007;
		maxl=0;
		cin>>n;
		while(n--){
			cin>>l>>r;
			minr=min(r,minr);
			maxl=max(l,maxl);
		}
		cout<<max(maxl-minr,0)<<'\n';
	}
	return 0;
}