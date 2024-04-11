#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll a,b,c,r,t,k=0,e=1e9;
int main(){
	cin>>t;
	f(i,0,t){
		cin>>a>>b>>c>>r;
		if(b<a) swap(b,a);
		cout<<max((b-a)-max(min(b,c+r)-max((c-r),a),k),k)<<endl;
	}
}