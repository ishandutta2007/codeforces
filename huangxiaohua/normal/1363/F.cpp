#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[2050][2050],num[505],no;
char s1[2050],s2[2050];
bool y[2050][2050];

int main(){
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s1+1>>s2+1;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				f[i][j]=y[i][j]=0;
			}
		}
		no=0;
		for(i=1;i<=n;i++){
			no+=!num[s1[i]];
			num[s1[i]]--;
			for(j=1;j<=n;j++){
				num[s2[j]]++;
				no-=!num[s2[j]];
				if(!no)y[i][j]=1;
			}
			if(i==n&&no){
				cout<<-1<<'\n';goto aaa;
			}
			for(j=1;j<=n;j++){
				no+=!num[s2[j]];
				num[s2[j]]--;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				f[i][j]=max(f[i-1][j],f[i][j-1]);
				if(s1[i]==s2[j]&&y[i][j]){
					f[i][j]=max(f[i-1][j-1]+1,f[i][j]);
				}
			}
		}
		cout<<n-f[n][n]<<'\n';
		aaa:;
		memset(num,0,sizeof(num));
	}
}