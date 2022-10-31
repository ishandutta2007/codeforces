#include <bits/stdc++.h>
using namespace std;

int i,j,k,t,n,m,sb;


int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		sb=0;
		for(i=0;i<n;i++){
			cout<<(sb^i)<<endl;
			cin>>j;
			if(j){goto aaa;}
			sb=i;
		}
		return 1;
		aaa:;
	}
}