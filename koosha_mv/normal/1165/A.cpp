#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int main(){
	int ans=0,x,y,z;
	string s;
	cin>>x>>y>>z>>s;
	f_(i,x-1,x-1-y+1){
		if(i!=s.size()-1-z && s[i]=='1') ans++;
		if(i==s.size()-1-z && s[i]=='0') ans++;
	}
	cout<<ans;
}