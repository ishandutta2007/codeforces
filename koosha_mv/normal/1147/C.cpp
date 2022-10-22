#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,x,mark[55];string p1="Alice",p2="Bob",k;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x;
		mark[x]++;
	}
	f(i,1,52){
		if(mark[i]>0){
			if(mark[i]>n/2)
				cout<<p2;
			else
				cout<<p1;
			return 0;
		}
	}
	cout<<p1;
}