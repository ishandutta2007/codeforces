#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=1e3+5,e=1e4;
string mp[N];
ll s1,s2,s3,n,m,x2[]={1,0,-1,0},y2[]={0,1,0,-1},dp[3][N][N],mn=1e9;
vector<int> stt1,stt2,stt3;
int dfs(int dis,vector<int> v,int p){
	if(v.size()==0) return 0;
	vector<int> v1;
	ll sz;
	for(int i=0;i<v.size();i++){
		dp[p][v[i]/e][v[i]%e]=dis;
		f(j,0,4){
			if(dp[p][v[i]/e+x2[j]][v[i]%e+y2[j]]==-1 && mp[v[i]/e+x2[j]][v[i]%e+y2[j]]!='#'){
				if(mp[v[i]/e+x2[j]][v[i]%e+y2[j]]=='1' && s1==0){
					s1=1;
					f(l,0,stt1.size())
						v.pb(stt1[l]);
				}
				if(mp[v[i]/e+x2[j]][v[i]%e+y2[j]]=='2' && s2==0){
					s2=1;
					f(l,0,stt2.size())
						v.pb(stt2[l]);
				}
				if(mp[v[i]/e+x2[j]][v[i]%e+y2[j]]=='3' && s3==0){
					s3=1;
					f(l,0,stt3.size())
						v.pb(stt3[l]);
				}
				if(mp[v[i]/e+x2[j]][v[i]%e+y2[j]]=='.')
					v1.pb(v[i]+(x2[j]*e)+y2[j]),dp[p][v[i]/e+x2[j]][v[i]%e+y2[j]]=-2;
			}
		}
	}
	dfs(dis+1,v1,p);
}
int main(){
	cin>>n>>m;
	f(i,1,n+1){
		cin>>mp[i];
		mp[i]='#'+mp[i]+'#';	
	}
	f(i,0,m+2) mp[0]+='#';
	mp[n+1]=mp[0];
	f(i,1,n+1){
		f(j,1,m+1){
			dp[0][i][j]=dp[1][i][j]=dp[2][i][j]=-1;
			if(mp[i][j]=='1')
				stt1.pb(i*e+j);
			if(mp[i][j]=='2')
				stt2.pb(i*e+j);
			if(mp[i][j]=='3')
				stt3.pb(i*e+j);	
		}
	}
	s1=1,s2=0,s3=0;dfs(0,stt1,0);
	s1=0,s2=1,s3=0;dfs(0,stt2,1);
	s1=0,s2=0,s3=1;dfs(0,stt3,2);
	f(i,1,n+1){
		f(j,1,m+1){
			if(mp[i][j]=='.'){
				if(dp[0][i][j]!=-1 && dp[1][i][j]!=-1 && dp[2][i][j]!=-1){
					mn=min(mn,dp[0][i][j]+dp[1][i][j]+dp[2][i][j]-2);
				}
			}
			else{
				if(dp[0][i][j]!=-1 && dp[1][i][j]!=-1 && dp[2][i][j]!=-1)
					mn=min(mn,dp[0][i][j]+dp[1][i][j]+dp[2][i][j]);
			}
		}
	}
	cout<<(mn*(mn!=1e9))+(-1*(mn==1e9));
}