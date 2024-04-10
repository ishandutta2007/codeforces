#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        10000007
#define hell2       15000000
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
string s;
int p,m,n,dp[10004][102][2],q[10004];
vi ad[10005];
void dfs1(int node,int m,int f){
    if(dp[node][m][f]<hell2) return;
    if(isdigit(s[node])){
        if(m==0) dp[node][0][f]=s[node]-'0';
        else if(f==0) dp[node][m][f]=-hell;
        else dp[node][m][f]=hell;
        return;
    }
    if(f==0){
        int ans=-hell;
        int q1=q[ad[node][0]],q2=q[ad[node][1]];
        int l=max(0,m-1-q2),r=min(q1,m)+1;
        rep(i,l,r){
            dfs1(ad[node][0],i,0);
            dfs1(ad[node][1],m-i-1,1);
            ans=max(ans,dp[ad[node][0]][i][0]-dp[ad[node][1]][m-i-1][1]);
        }
        l=max(0,m-q2);
        rep(i,l,r){
            dfs1(ad[node][0],i,0);
            dfs1(ad[node][1],m-i,0);
            ans=max(ans,dp[ad[node][0]][i][0]+dp[ad[node][1]][m-i][0]);
        }
        dp[node][m][f]=ans;
    }
    else{
        int ans=hell;
        int q1=q[ad[node][0]],q2=q[ad[node][1]];
        int l=max(0,m-1-q2),r=min(q1,m)+1;
        rep(i,l,r){
            dfs1(ad[node][0],i,1);
            dfs1(ad[node][1],m-i-1,0);
            ans=min(ans,dp[ad[node][0]][i][1]-dp[ad[node][1]][m-i-1][0]);
        }
        l=max(0,m-q2);
        rep(i,l,r){
            dfs1(ad[node][0],i,1);
            dfs1(ad[node][1],m-i,1);
            ans=min(ans,dp[ad[node][0]][i][1]+dp[ad[node][1]][m-i][1]);
        }
        dp[node][m][f]=ans;
    }
}
void dfs2(int node,int p,int f){
    if(dp[node][p][f]<hell2) return;
    if(isdigit(s[node])){
        if(p==0) dp[node][0][f]=s[node]-'0';
        else if(f==0) dp[node][p][f]=-hell;
        else dp[node][p][f]=hell;
        return;
    }
    if(f==0){
        int ans=-hell;
        int q1=q[ad[node][0]],q2=q[ad[node][1]];
        int l=max(0,p-1-q2),r=min(q1,p)+1;
        rep(i,l,r){
            dfs2(ad[node][0],i,0);
            dfs2(ad[node][1],p-i-1,0);
            ans=max(ans,dp[ad[node][0]][i][0]+dp[ad[node][1]][p-i-1][0]);
        }
        l=max(0,p-q2);
        rep(i,l,r){
            dfs2(ad[node][0],i,0);
            dfs2(ad[node][1],p-i,1);
            ans=max(ans,dp[ad[node][0]][i][0]-dp[ad[node][1]][p-i][1]);
        }
        dp[node][p][f]=ans;
    }
    else{
        int ans=hell;
        int q1=q[ad[node][0]],q2=q[ad[node][1]];
        int l=max(0,p-1-q2),r=min(q1,p)+1;
        rep(i,l,r){
            dfs2(ad[node][0],i,1);
            dfs2(ad[node][1],p-i-1,1);
            ans=min(ans,dp[ad[node][0]][i][1]+dp[ad[node][1]][p-i-1][1]);
        }
        l=max(0,p-q2);
        rep(i,0,p+1){
            dfs2(ad[node][0],i,1);
            dfs2(ad[node][1],p-i,0);
            ans=min(ans,dp[ad[node][0]][i][1]-dp[ad[node][1]][p-i][0]);
        }
        dp[node][p][f]=ans;
    }
}
void solve(){
    memset(dp,1,sizeof dp);
    cin>>s>>p>>m;
    if(sz(s)==1) {cout<<s;return;}
    stack<int> stk;
    n=sz(s);
    rep(i,0,n){
        if(s[i]=='('){
            if(!stk.empty())
            ad[stk.top()].pb(i);
            stk.push(i);
        }
        else if(s[i]==')'){
            q[stk.top()]=(i-stk.top())/4;
            stk.pop();

        }
        else if(s[i]!='?'){
            ad[stk.top()].pb(i);
            q[stk.top()]=0;
        }
    }
    if(m<p){
        dfs1(0,m,0);
        cout<<dp[0][m][0]<<endl;
    }
    else{
        dfs2(0,p,0);
        cout<<dp[0][p][0]<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}