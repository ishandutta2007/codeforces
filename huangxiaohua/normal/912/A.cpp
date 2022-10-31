#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a,b,c,d,e,res;

int main(){
	cin>>a>>b>>c>>d>>e;
	res+=max(0ll,c*2+d-a);
	res+=max(0ll,d+e*3-b);
	cout<<res;
}