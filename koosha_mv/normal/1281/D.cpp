#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b)for(ll i=a;i>=b;i--)
#define	ll long long
#define pb push_back
ll n,m,q,a,p,r,jj1,j2,j3,j4,so,k;
string s[62];
int main(){
	cin>>q;
	f(i,0,q){
		jj1=0;j2=0;j3=0;
		cin>>n>>m;a=0,p=0,r=1;
		f(i,0,n){
			cin>>s[i];r=1;
			f(j,0,s[i].size()){
				if(s[i][j]=='P') r=0; 
				if(s[i][j]=='A') a=1;
				else p=1;
			}
			if(r==1){
					if(i==0 || i==n-1)
						jj1=1;
					else j2=1;
				}
		}
		if(p==0) cout<<0;
		else{
			if(a==0) cout<<"MORTAL";
			else{
				f(i,0,m){
					so=1;
					f(j,0,n){
						if(s[j][i]=='P')
							so=0;
					}
				if(so==1){
					if(i==0 || i==m-1) jj1=1;
					else j2=1;
				}
				}
			
			if(s[0][0]=='A' || s[0][m-1]=='A' || s[n-1][0]=='A' || s[n-1][m-1]=='A') j2=1;
			f(i,0,m){
				if(s[0][i]=='A') j3=1;
			}
			f(i,0,n){
				if(s[i][0]=='A') j3=1;
			}
			f(i,0,m){
				if(s[n-1][i]=='A') j3=1;
			}
			f(i,0,n){
				if(s[i][m-1]=='A') j3=1;
			}
			if(jj1>=1) cout<<1;
			else{
				if(j2>=1) cout<<2;
				else{
					if(j3>=1) cout<<3;
					else cout<<4;
				}
			}
		}
		}
		cout<<endl;
	}
}