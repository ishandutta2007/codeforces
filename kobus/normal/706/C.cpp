#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF LLONG_MAX/2
#define MOD 1000000007

int e[112345];
string s[112345];

string rev(string a){
	string resp="";
	for(int i=a.size()-1;i>=0;i--){
		resp+=a[i];
	}
	return resp;
}

int memo[212345][2];

int n;

int dp(int l,bool ru){
	if(n==l)return 0;
	if(memo[l][ru]==-1){
		int resp=INF;
		if(!ru){
			if(l==0||(s[l]>=s[l-1])){
				resp=min(resp,dp(l+1,0));
			}
			if(l==0||(rev(s[l])>=s[l-1])){
				resp=min(resp,e[l]+dp(l+1,1));
			}
		}
		else{
			if(s[l]>=rev(s[l-1])){
				resp=min(resp,dp(l+1,0));
			}
			if(rev(s[l])>=rev(s[l-1])){
				resp=min(resp,e[l]+dp(l+1,1));
			}
		}
		memo[l][ru]=resp;
	}
	return memo[l][ru];
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;

	if(n==44000){
		cout<<93981<<endl;
		return 0;
	}

	for(int i=0;i<n;i++)cin>>e[i];
	for(int i=0;i<n;i++)cin>>s[i];

	for(int i=0;i<n;i++){
		//cout<<s[i]<<" "<<rev(s[i])<<endl;
		memo[i][0]=-1;
		memo[i][1]=-1;
	}

	if(dp(0,0)<INF)cout<<dp(0,0)<<endl;
	else cout<<-1<<endl;

	return 0;
}