#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
int sb[100500][27];
char s[100500];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>s+1;
			for(j=1;j<=m;j++){
				sb[j][s[j]-'a'+1]++;
			}
		}
		for(i=1;i<=n-1;i++){
			cin>>s+1;
			for(j=1;j<=m;j++){
				sb[j][s[j]-'a'+1]--;
			}
		}
		for(i=1;i<=m;i++){
			for(j=1;;j++){
				if(sb[i][j]){
					cout<<(char)(j+'a'-1);
					sb[i][j]=0;break;
				}
			}
		}
		cout<<endl;
	}
}