#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a1,b1,a2,b2,a3,b3;
map<pair<int,int>,int >nmsl;
int main() {
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	vector<vector<bool> >vis(n+2,vector<bool>(m+2) );
	for(i=0;i<=m+1;i++)vis[0][i]=vis[n+1][i]=1;
	for(i=0;i<=n+1;i++)vis[i][0]=vis[i][m+1]=1;
	for(i=0;;i++){
		a1=i+1;b1=i+1;
		a2=n-i;b2=m-i;
		
		//printf("NMSL%d %d\n",a1,a2);
		if(a1>a2||b1>b2)break;
		if(i&1){
			swap(a1,a2);swap(b1,b2);
			//printf("NMSL%d %d\n",a1,a2);
			while(1){
				if(!vis[a1][b1]){
					//if(nmsl[{a1-a3,b1-b3}])return 1;
					cout<<a1<<' '<<b1<<'\n';
					vis[a1][b1]=1;
					//nmsl[{a1-a3,b1-b3}]=1;
					a3=a1;b3=b1;
					
				}
				if(!vis[a2][b2]){
					//if(nmsl[{a2-a3,b2-b3}])return 1;
					cout<<a2<<' '<<b2<<'\n';
					vis[a2][b2]=1;
					//nmsl[{a2-a3,b2-b3}]=1;
					a3=a2;b3=b2;
				}
				
				if(!vis[a2][b2+1]){
					b2++;b1--;
				}
				else if(!vis[a2+1][b2]){
					a2++;a1--;
				}
				else break;
			}
		}
		else{
			while(1){
				if(!vis[a1][b1]){
					//if(nmsl[{a1-a3,b1-b3}])return 1;
					cout<<a1<<' '<<b1<<'\n';
					vis[a1][b1]=1;
					//nmsl[{a1-a3,b1-b3}]=1;
					a3=a1;b3=b1;
					
				}
				if(!vis[a2][b2]){
					//if(nmsl[{a2-a3,b2-b3}])return 1;
					cout<<a2<<' '<<b2<<'\n';
					vis[a2][b2]=1;
					//nmsl[{a2-a3,b2-b3}]=1;
					a3=a2;b3=b2;
				}
				
				if(!vis[a1][b1+1]){
					b1++;b2--;
				}
				else if(!vis[a1+1][b1]){
					a1++;a2--;
				}
				else break;
			}
		}
	}
}