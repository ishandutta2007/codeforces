#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>s>>m;
		for(auto i:s)a[i]++,m-=(i-'a'+1);
		for(i='z';i>='a';i--){
			while(a[i]&&m<0){
				m+=i-'a'+1;
				a[i]--;
			}
		}
		for(auto i:s){
			if(a[i]){
				a[i]--;cout<<i;
			}
		}
		cout<<endl;
	}
}