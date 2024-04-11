#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll t,h,m;
int main(){
	cin>>t;
	f(i,0,t){
		cin>>h>>m;
		cout<<(23-h)*60+(60-m)<<endl;
	}
}