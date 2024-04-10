#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,l,r;
char sb[105];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>sb+1;
		n=strlen(sb+1);
		if(n%2){puts("NO");continue;}
		for(i=1;i<=n;i++){
			if(sb[i]=='('){l=i;}
			if(sb[i]==')'){r=i;}
			
		}
		if(l<r){puts("YES");continue;}
		if(r==1||l==n){puts("NO");continue;}
		puts("YES");
	}
}