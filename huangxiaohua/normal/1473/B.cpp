#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,t,m;
string a,b,tmp,tmp2;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>a;cin>>b;
		n=a.size();m=b.size();
		tmp.clear();
		for(i=1;i<=21;i++){
			tmp+=a;
			if(i*n%m){continue;}
			tmp2.clear();
			for(j=1;j<=i*n/m;j++){
				tmp2+=b;
			}
			if(tmp==tmp2){cout<<tmp<<endl;goto aaa;}
		}
		cout<<-1<<endl;
		aaa:;
	}
}