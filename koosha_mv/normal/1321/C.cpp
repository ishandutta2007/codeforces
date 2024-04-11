#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+99;
ll n,ans=0,dp[200][160][30],mx,ghmx=1000,p1,p2;
vector<char> s;
char t;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>t;
		s.pb(t);
	}
	f(j,0,30){
	//	f(i,0,s.size()) cout<<s[i];
	//	cout<<endl;
		f(i,0,s.size())
			if(int(s[i])<ghmx) maxm(mx,1ll*s[i]);
	//	cout<<mx-'a'<<endl;
		f_(i,s.size()-1,0){
			if(int(s[i])==mx){
				p1=i,p2=i;
				while(p1>0 && s[p1]==s[i]) p1--;
				while(p2<s.size()-1 && s[p2]==s[i]) p2++;
				if((int(s[p1])==int(s[i])-1) || int(s[p2])==int(s[i])-1){
					ans++;
					s.erase(s.begin()+i);
				}
			}
		}
		ghmx=mx;
		mx=0;
	}
	cout<<ans;
}