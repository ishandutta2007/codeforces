#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=2e5+99;
int t,n,a[N],k,p;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		k=0;
		f(i,0,n){
			gett(a[i]);
			if(i>0 && a[i]!=a[i-1])
			 	k++;
		}
		if(k==0){
			cout<<1<<endl;
			f(i,0,n) cout<<1<<" ";
		}
		else{
			p=-1;
			if(a[0]==a[n-1]) p=0;
			f(i,1,n) if(a[i]==a[i-1]) p=i;
			if(n%2==0) p=0;
			if(n%2==0){
				cout<<2<<endl;
				f(i,0,n) cout<<i%2+1<<" ";
			}
			else{
				if(p>=0){
					cout<<2<<endl;
					f(i,0,n){
						if(i<p)
							cout<<i%2+1<<" ";
						else 
							cout<<(i+1)%2+1<<" ";
					}
				}
				else{
				cout<<3<<endl;
				cout<<3<<" ";
				f(i,1,n) cout<<i%2+1<<" ";
				}
			}
		}
		cout<<endl;
	}
}