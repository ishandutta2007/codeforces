#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char sb[200500];
int i,j,k,n,t,an,bn,res;
int main(){
	cin>>t;
	while(t--){
		cin>>sb+1;
		an=bn=res=0;
		n=strlen(sb+1);
		for(i=1;i<=n;i++){
			if(sb[i]=='('){an++;}
			if(sb[i]=='['){bn++;}
			
			if(sb[i]==')'){if(an){an--;res++;}}
			if(sb[i]==']'){if(bn){bn--;res++;}}
		}
		printf("%d\n",res);
	}
}