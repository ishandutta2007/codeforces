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
const int N=3e5+9;
ll n,mark[32],ans=1,t,a;
string s;
int main(){
	cin>>s;
	f(i,0,s.size()){
		mark[s[i]]++;
		maxm(ans,mark[s[i]]*(mark[s[i]]-1)/2);
		maxm(ans,mark[s[i]]);
	}
	f(i,0,27){
		f(j,0,27){
			if(i!=j){
				t=0,a=0;
				f(l,0,s.size()){
					if(s[l]-'a'==i) t++;
					if(s[l]-'a'==j){
						a+=t;
					}
				}
				maxm(ans,a);
			}
		}
	}
	cout<<ans<<endl;
}