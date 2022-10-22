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
const int N=1e5+9;
ll n,q1,mark1[N][35],mark2[35],ans=1,gh=-1,k;
string s,t;
int main(){
	cin>>q1;
	f(q,0,q1){
		cin>>s>>t;
		f_(i,s.size()+1,0){
			f(j,0,35)
				mark1[i][j]=-1;
		}
		f(j,0,34) mark2[j]=-1;
		f_(i,s.size()-1,0){
			f(j,0,35){
				if(s[i]-'a'==j)
					mark1[i][j]=i;
				else
					mark1[i][j]=mark1[i+1][j];
			}
		}
		f(i,0,s.size()){
			if(mark2[s[i]-'a']==-1)
				mark2[s[i]-'a']=i;
		}
		ans=1;
		gh=-1;k=0;
		f(i,0,t.size()){
			if(mark1[gh+1][t[i]-'a']==-1){
				ans++;
				gh=mark2[t[i]-'a'];
				if(mark2[t[i]-'a']==-1){
					k=1;
				}
			}
			else{
				gh=mark1[gh+1][t[i]-'a'];
			}
		}
		if(k==1) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}