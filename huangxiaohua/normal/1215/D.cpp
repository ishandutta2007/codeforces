#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,l,r,a,b;
char s[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>s+1;
	for(i=1;i<=n;i++){
		if(s[i]=='?'){
			if(i<=n/2){l++;}
			else{r++;}
		}
		else{
			if(i<=n/2){a+=s[i]-'0';}
			else{b+=s[i]-'0';}
		}
	}
	k=min(l,r);l-=k;r-=k;
	if(l){
		l/=2;
		a+=l*9;
		if(a!=b){cout<<"Monocarp";return 0;}
		else{cout<<"Bicarp";return 0;}
	}
	else{
		r/=2;
		b+=r*9;
		if(a!=b){cout<<"Monocarp";return 0;}
		else{cout<<"Bicarp";return 0;}
	}
}