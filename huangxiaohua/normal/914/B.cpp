#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res=-1145141919;
bool sb[1005000];
int main(){
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		sb[k]^=1;
	}
	for(i=100000;i>=0;i--){
		if(sb[i]){
			cout<<"Conan";
			return 0;
		}
	}
	cout<<"Agasa";
}