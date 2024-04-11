#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,k,ans;
string s[1509];
map <string,ll> mark;
char nt(char x,char y){
	ll v1,v2;
	if((x=='E')+(y=='E')+(x=='T')+(y=='T')==2) return 'S';
	if((x=='E')+(y=='E')+(x=='S')+(y=='S')==2) return 'T';
	return 'E';
}
int main(){
	cin>>n>>k;
	f(i,0,n){
		cin>>s[i];
		mark[s[i]]++;
	}
	f(i,0,n){
		f(j,i+1,n){
			string s1;
			f(p,0,k){
				if(s[i][p]==s[j][p])
					s1+=s[i][p];
				else
					s1+=nt(s[i][p],s[j][p]);	
			}
			if(s1==s[i]) ans+=mark[s1]-2;
			else ans+=mark[s1];
		}
	}
	cout<<ans/3;
}