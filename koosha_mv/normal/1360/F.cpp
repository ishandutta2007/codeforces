#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=12;

int n,m,t,a[N];
bool dp[(1<<N)];
string par[(1<<N)],s[N];

bool check(int x,int y){
	f(i,0,N){
		if(x%2==0 && y%2==1) return 0;
		x/=2,y/=2;
	}
	return 1;
}

int main(){
	cin>>t;
	while(t--){
		string res="";
		cin>>n>>m;
		dp[0]=1,par[0]="";
		f(i,1,(1<<n)) dp[i]=0,par[i]="";
		f(i,0,n)
			cin>>s[i];
		f(i,0,m){
			f_(j,(1<<n)-1,0){
				int ans=0;
				f(k,0,26){
					int p=0;
					f(l,0,n)
						if(s[l][i]-'a'!=k)
							p+=(1<<l);
					if(check(j,p) && dp[j-p]) ans=1,par[j]=par[j-p]+char('a'+k);
				}
				dp[j]=ans;
			}
		}
		f(i,0,(1<<n)) if(dp[i]) res=par[i];
		if(res=="") cout<<-1;
		else cout<<res;
		cout<<endl;
	}
}