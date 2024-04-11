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
const int N=4e5+9;
ll n,t,l,r,ans,mark1[N][32];
string s;
int main(){
	cin>>s;s=' '+s;
	f(i,1,s.size()){
		f(j,0,32)
			mark1[i][j]=mark1[i-1][j];
		mark1[i][s[i]-'a']++;
	}
	cin>>t;
	f(q,0,t){
		cin>>l>>r;
		ans=0;l--;
		f(i,0,32){
			if(mark1[r][i]>mark1[l][i])
				ans++;
		}
		if(ans>2 || (ans==2 && s[l+1]!=s[r]) || l+1==r)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}