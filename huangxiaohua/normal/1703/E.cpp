#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[2],res;
string s[1005];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>s[i];
			s[i]="X"+s[i];
		}
		res=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				int x1,y1,x2,y2,x3,y3,x4,y4;
				x1=i;	y1=j;
				x2=n+1-j; y2=i;
				x3=n+1-i; y3=n+1-j;
				x4=j; y4=n+1-i;
				//printf("a%d %d %d %d %d %d %d %d\n",x1,y1,x2,y2,x3,y3,x4,y4);
				vector<pair<int,int> >v={{x1,y1},{x2,y2},{x3,y3},{x4,y4}};
				f[0]=f[1]=0;
				for(auto [x,y]:v){
					f[s[x][y]-'0']++;
				}
				if(f[0]>f[1]){
					res+=f[1];
					for(auto [x,y]:v){
						s[x][y]='0';
					}
				}
				else{
					res+=f[0];
					for(auto [x,y]:v){
						s[x][y]='1';
					}
				}
			}
		}
		cout<<res<<endl;
	}
}