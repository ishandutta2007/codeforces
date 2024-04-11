#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int mx[200009],mn[200009],t,n;
pair <int,int> p[200009];
int main(){
	cin>>t;
	f(sa,0,t){
		cin>>n;
		f(i,0,n){
			cin>>p[i].first;p[i].second=i;
		}
		sort(p,p+n);
		mn[0]=1e9;
		f(i,0,n){
			mx[i+1]=max(mx[i],p[i].second);
			mn[i+1]=min(mn[i],p[i].second);
		}
		f(i,1,n+1){
			if(mx[i]-mn[i]==i-1)
				cout<<'1';
			else
				cout<<'0';
		}
		cout<<endl;
	}
}