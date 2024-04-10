#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t,m;
char sb[105];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>sb+1;
		m=0;
		for(i=n;i>=1;i--){
			if(sb[i]==')'){m++;}else{break;}
		}
		puts((m*2>n)?"yES":"nO");
	}
}