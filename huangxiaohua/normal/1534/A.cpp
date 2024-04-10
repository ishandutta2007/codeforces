#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t;
char s[105][105];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>s[i]+1;
		}
		
		int sb=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(s[i][j]=='.'){continue;}
				k=(i+j);
				if(k&1){
					if(s[i][j]!='R'){sb=0;break;}
				}
				else{
					if(s[i][j]!='W'){sb=0;break;}
				}
			}
		}
		if(sb){
			cout<<"YES"<<endl;
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					k=i+j;
					if(k&1){
						cout<<'R';
					}
					else{
						cout<<'W';
					}
				}
				cout<<endl;
			}
			continue;
		}
		
		sb=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(s[i][j]=='.'){continue;}
				k=(i+j);
				if(k&1){
					if(s[i][j]!='W'){sb=0;break;}
				}
				else{
					if(s[i][j]!='R'){sb=0;break;}
				}
			}
		}
		if(sb){
			cout<<"YES"<<endl;
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					k=i+j;
					if(k&1){
						cout<<'W';
					}
					else{
						cout<<'R';
					}
				}
				cout<<endl;
			}
			continue;
		}
		
		cout<<"NO"<<endl;
	}
}