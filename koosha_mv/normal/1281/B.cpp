#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b)for(ll i=a;i>=b;i--)
#define	ll long long
#define pb push_back
int q,k,o,mark[160],e,t,mn1,a1,mn2,a2,kh;
string s,p;
int main(){
	cin>>q;
	f(sal,0,q){
		cin>>s>>p;k=0,t=0,mn1=1e9,a1=0;
		if(s<p) cout<<s<<endl;
		else{
			kh=0;
			f_(i,s.size()-1,0){
				if(s[i]<mn1){
					mn1=s[i];a1=i;
				}
				if(i!=s.size()-1){
					swap(s[i],s[a1]);
					if(s<p){
						kh=1;break;
					}
					else swap(s[i],s[a1]);
				}
			}
			if(kh==1){cout<<s<<endl;}
			else{
				cout<<"---"<<endl;
		}
		}
	}
}