#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b)for(ll i=a;i>=b;i--)
#define	ll long long
#define pb push_back
ll n,k;
string s;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>s;
		k=s.size();
		if(s[k-1]=='o' && s[k-2]=='p') cout<<"FILIPINO";
		else{
			if(s[k-1]=='u') cout<<"JAPANESE";
			else cout<<"KOREAN";
		}
		cout<<endl;
	}
}