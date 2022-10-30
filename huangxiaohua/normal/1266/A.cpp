#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a0,a[11],b[11],sb;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;
		memset(a,0,sizeof(a));
		sb=0;
		for(auto i:s){
			a[i-'0']++;
			sb+=i-'0';
		}
		if(!a[0]){cout<<"cyan"<<endl;continue;}
		a[0]--;
		if(sb%3){cout<<"cyan"<<endl;continue;}
		for(i=0;i<=8;i+=2){
			if(a[i]){cout<<"red"<<endl;goto aaa;}
		}
		cout<<"cyan"<<endl;
		aaa:;
	}
}