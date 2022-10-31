#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,sum,p,x[500500],y[500500];
vector<vector<int> >mp,mp2;
string s[500500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;res=0;sum=n+m-1;
		vector<int> v(m+3);
		for(i=1;i<=n;i++){
			cin>>s[i];
			s[i]="X"+s[i];
		}
		
		for(i=1;i<=n;i++){
			x[i]=0;
			for(j=1;j<=m;j++){
				x[i]+=(s[i][j]=='*');
			}
		}

		for(i=1;i<=m;i++){
			y[i]=0;
			for(j=1;j<=n;j++){
				y[i]+=(s[j][i]=='*');
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				res=max(res,x[i]+y[j]-(s[i][j]=='*'));
			}
		}
		
		cout<<sum-res<<endl;
	}
}