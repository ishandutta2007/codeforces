#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,k,mark[150];
string s;
char x;
int main(){
	cin>>n>>k>>s;
	f(i,0,k){
		cin>>x;
		mark[int(x)]=1;
	}
	ll gh=-1,sum=0;
	f(i,0,s.size()){
		if(mark[s[i]]==0){
			sum+=(i-1-gh)*(i-1-gh+1)/2;
			gh=i;
		}
	}
	sum+=(s.size()-1-gh)*(s.size()-1-gh+1)/2;
	cout<<sum;
}