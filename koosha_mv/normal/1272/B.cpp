#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll q,r,u,l,d;
string s;
int main(){
	cin>>q;
	f(sal,0,q){
		cin>>s;r=0,u=0,l=0,d=0;
		f(i,0,s.size()){
			if(s[i]=='R') r++;
			if(s[i]=='D') d++;
			if(s[i]=='U') u++;
			if(s[i]=='L') l++;
		}
		r=min(r,l);l=r;
		u=min(u,d);d=u;
		if(r==0 & u>=1) u=1,d=1;
		if(u==0 & r>=1) r=1,l=1;
		cout<<r+l+d+u<<endl;
		f(i,0,r) cout<<'R';
		f(i,0,u) cout<<'U';
		f(i,0,l) cout<<'L';
		f(i,0,d) cout<<'D';
		cout<<endl; 
	}
}