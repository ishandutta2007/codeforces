#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200500][30],l,r,b[30];
char s[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>s+1>>t;
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		s[i]-='a'-1;
		for(j=1;j<=26;j++){
			f[i][j]=f[i-1][j];
		}
		f[i][s[i]]++;
	}
	while(t--){
		cin>>l>>r;k=0;
		for(i=1;i<=26;i++){
			b[i]=f[r][i]-f[l-1][i];
			if(b[i]){k++;}
		}
		if(r==l){cout<<"Yes"<<endl;continue;}
		if(k==1){cout<<"No"<<endl;continue;}
		if(k>=3){cout<<"Yes"<<endl;continue;}
		if(s[l]!=s[r]){cout<<"Yes"<<endl;continue;}
		else{cout<<"No"<<endl;continue;}
	}
}