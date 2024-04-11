#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
string s;ll n;
int main(){
	cin>>s;
	n=(s[s.size()-2]-'0')*10+(s[s.size()-1]-'0');
	if(n%4==0) cout<<4;
	else cout<<0;
}