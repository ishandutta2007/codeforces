#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=219;
ll n,dp1[N][32][32];
string s,dp2[N][32][32];
int main(){
	cin>>n>>s;
	dp1[0][s[0]-'a'][0]=1,dp2[0][s[0]-'a'][0]='1';
	f(q,1,n){
		f(i,0,s[q]-'a'+1){
			f(j,0,29){
				if(dp1[q-1][i][j]){
					dp1[q][s[q]-'a'][j]=1,dp2[q][s[q]-'a'][j]=dp2[q-1][i][j]+'1';
				}
			}
		}
		f(i,0,s[q]-'a'+1){
			f(j,0,29){
				if(dp1[q-1][j][i]){
					dp1[q][j][s[q]-'a']=1,dp2[q][j][s[q]-'a']=dp2[q-1][j][i]+'0';
				}
			}
		}
	}
	f(i,0,29){
		f(j,0,29){
			if(dp1[n-1][i][j]){
				cout<<"YES"<<endl<<dp2[n-1][i][j];
				return 0;
			}
		}
	}
	cout<<"NO";
}