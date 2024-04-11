#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,s1,s2,t1,t2,m1,m;
string s;
int main(){
	cin>>n>>s;
	f(i,0,n){
		if(i<n/2){
			if(s[i]=='?')
				t1++;
			else
				s1+=int(s[i]-'0');
		}
		else{
			if(s[i]=='?')
				t2++;
			else
				s2+=int(s[i]-'0');
		}
	}
	if(t1%2==1) t1--,t2--;
	m=(t1-t2)/2,m1=(t2-t1)/2;
	if(t1%2!=t2%2 || (m*9)+s1!=s2)
		cout<<"Monocarp";
	else
		cout<<"Bicarp";
}