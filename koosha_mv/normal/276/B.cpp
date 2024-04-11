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
string s;
ll mark[160],f;
int main(){
	cin>>s;
	f(i,0,s.size()){
		mark[s[i]]++;
		if(mark[s[i]]%2==1)
			f++;
		else
			f--;
	}
	if(f<=1 || f%2==1) cout<<"First";
	else cout<<"Second";
}