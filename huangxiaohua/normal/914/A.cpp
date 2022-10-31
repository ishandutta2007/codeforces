#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res=-1145141919;
bool sb[1005000];
int main(){
	cin.tie(0);
	for(i=0;i<=1000;i++){
		sb[i*i]=1;
	}
	cin>>t;
	while(t--){
		cin>>k;
		if(k<0||!sb[k]){
			res=max(res,k);
		}
	}
	cout<<res;
}