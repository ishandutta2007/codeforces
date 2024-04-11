#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=200;
ll n,m,t[N],g[N],k,mark[N];
string s[N],ans,s1,ans1,ans2,ans3;
string pal(string a){
	string anss="";
	f_(i,a.size()-1,0)
		anss+=a[i];
	return anss;
}
int main(){
	cin>>n>>m;
	f(i,0,n) cin>>s[i];
	f(i,0,n){
		k=-1;
		s1=pal(s[i]);
		if(mark[i]==0){
			k=-1;
			f(j,i+1,n){
				if(s[j]==s1 && mark[j]==0){
					k=j;
					mark[j]=1;
					break;
				}
			}
			if(k!=-1)
				ans1+=s[i];
		}
	}
	f(i,0,n){
		if(mark[i]==0 && pal(s[i])==s[i]){
			ans2=s[i];
			break;
		}
	}
	cout<<ans1.size()*2+ans2.size()<<endl;
	ans3=pal(ans1);
	cout<<ans1<<ans2<<ans3;
}