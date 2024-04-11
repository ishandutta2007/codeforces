#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+9;

int n,t,k;

int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>k;
		if(n%2){
			if(k%2==0 || k>n) cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
				f(i,0,k-1) cout<<1<<" ";
				cout<<n-(k-1)<<endl;
			}
		}
		else{
			if(k%2){
				if(k*2>n) cout<<"NO"<<endl;
				else{
					cout<<"YES"<<endl;
					f(i,0,k-1) cout<<2<<" ";
					cout<<n-k*2+2<<endl;
				}
			}
			else{
				if(k>n) cout<<"NO"<<endl;
				else{
					cout<<"YES"<<endl;
				f(i,0,k-1) cout<<1<<" ";
				cout<<n-(k-1)<<endl;
				}
			}
		}
	}
}