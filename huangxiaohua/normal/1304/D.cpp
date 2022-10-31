#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,tmp,res[200500];
char s[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s+1;
		
		k=1;it=n;
		s[n]='>';
		for(i=1;i<=n;i++){
			if(s[i]=='<'){
				k++;
			}
			else{
				for(j=it-k+1;j<=it;j++){
					cout<<j<<' ';
				}
				it-=k;
				k=1;
			}
		}
		cout<<'\n';
		
		s[n]='<';
		memset(res,0,n*4+50);
		it=0;
		for(i=1;i<=n;i++){
			if(s[i]=='<'){
				res[i]=++it;
			}
		}
		it=n;
		for(i=1;i<=n;i++){
			if(!res[i]){
				res[i]=it;it--;
			}
		}
		for(i=1;i<=n;i++){
			cout<<res[i]<<' ';
		}
		cout<<'\n';
		
		
	}
}