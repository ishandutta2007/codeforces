#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define pb push_back
#define mod 998244353
#define pn cout<<"No\n"
#define py cout<<"Yes\n"

vector<int>son[N];
int T,n,a[N],s,i,j,x,y,z,k,c[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		x=s/(n/2+1)+(s%(n/2+1)>(n>>1));
		cout<<x<<"\n";
	}
}