#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,a[200099],mark[200099],p1,b[200099],b2[200099],p2;
int main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		if(a[i]==0){
			b2[p2]=i;
			p2++;
		}
		mark[a[i]]++;
	}
	f_(i,n,1){
		if(mark[i]==0){
			b[p1]=i;
			p1++;
		}
	}
	f(i,0,p1){
		if(b[i]==b2[i]){
			if(i!=0){
				swap(b[i],b[i-1]);
			}
			else swap(b[i],b[i+1]);
		}
	}
	f(i,0,p1){
		a[b2[i]]=b[i];
	}
	f(i,1,n+1) cout<<a[i]<<" ";
}