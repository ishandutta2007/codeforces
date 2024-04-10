#include<bits/stdc++.h>
using namespace std;
int n,k;
string s,t;
int main(){
	cin>>n>>k>>s;
	for(int i=0;i<=n;i++){
		int j;
		for(j=0;j<k;j++){
			if(i*k+j<n){
				t.push_back(s[j]);
			}
			else{
				break;
			}
		}
		if(j<k){
			break;
		}
	}
	if(s<=t){
		cout<<t.length()<<'\n'<<t;
	}
	else{
		bool t=1;
		for(int i=k-1;i>=0;i--){
			if(!t){
				break;
			}
			if(s[i]=='9'){
				s[i]='0';
			}
			else{
				s[i]++;
				t=0;
			}
		}
		cout<<n<<'\n';
		for(int i=0;i<=n;i++){
			int j;
			for(j=0;j<k;j++){
				if(i*k+j<n){
					cout<<s[j];
				}
				else break;
			}
			if(j<k){
				break;
			}
		}
	}
	return 0;
}