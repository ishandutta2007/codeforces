#include<bits/stdc++.h>
using namespace std;
int t,n,x;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int fl=0;
		for(int i=1;i<=n;++i){
			cin>>x;
			if((int)(sqrt(x))*(int)(sqrt(x))!=x){
				fl=1;
			}
		}
		puts(fl?"YES":"NO");
	}
	return 0;
}