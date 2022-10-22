#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll n,w=0,kh[700],sk,b;string s;
int main(){
	cin>>n>>s;
	f(i,0,s.size()){
		if(s[i]=='W') w++;
	}
	b=n-w;
	if(w%2==1 && b%2==1) {cout<<-1;return 0;}
	if(w%2==0){
		f(i,0,n-1){
			if(s[i]=='W'){
				kh[sk]=i;
				sk++;
				if(s[i+1]=='B') s[i+1]='W';
				else s[i+1]='B';
			}
		}
	}
	else{
		f(i,0,n-1){
			if(s[i]=='B'){
				kh[sk]=i;
				sk++;
				if(s[i+1]=='B') s[i+1]='W';
				else s[i+1]='B';
			}
		}
	}
	cout<<sk<<endl;
	f(i,0,sk) cout<<kh[i]+1<<" ";
}