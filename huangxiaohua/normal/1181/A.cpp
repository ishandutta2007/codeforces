#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],b[100500],it;
ll x,y,z,r1,sb;

int main(){
	cin>>x>>y>>z;
	r1=(x+y)/z;
	sb=x/z+y/z;
	cout<<r1<<' ';
	if(sb==r1){
		cout<<0;return 0;
	}
	x%=z;y%=z;
	cout<<min(z-x,z-y);
}