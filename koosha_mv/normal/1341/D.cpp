#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3000;

int n,t,k;
bool dp[N][N],o;
string s[N],ans,b[10];
vector<pair<int,int> > g[N];
void make(){
	b[0]= "1110111", b[1]="0010010", b[2]="1011101", b[3]="1011011", b[4]="0111010", b[5]="1101011", b[6]="1101111", b[7]="1010010", b[8]="1111111", b[9]="1111011";
}
void solve(int x){
	f(i,0,g[x].size()){
		if(k-g[x][i].S>=0 && dp[x+1][k-g[x][i].S]){
			ans+=char(g[x][i].F+'0');
			k-=g[x][i].S;
			return ;
		}
	}
	cout<<-1;
	exit(0);
}
int main(){
	make();
	cin>>n>>k;
	f(i,0,n) cin>>s[i];
	f(i,0,n){
		f(j,0,10){
			o=1,t=0;
			f(k1,0,7){
				if(s[i][k1]=='1' && b[j][k1]=='0') o=0;
				if(s[i][k1]=='0' && b[j][k1]=='1') t++;
			}
			if(o)
				g[i].pb(mp(j,t));
		}
		sort(g[i].begin(),g[i].end());
		reverse(g[i].begin(),g[i].end());
	}
	dp[n][0]=1;
	f_(i,n-1,0){
		f_(l,k,0){
			f(j,0,g[i].size())
				if(g[i][j].S<=l)
					dp[i][l]=(dp[i][l] || dp[i+1][l-g[i][j].S]);
		}
	}
	f(i,0,n)
		solve(i);
	cout<<ans;
}