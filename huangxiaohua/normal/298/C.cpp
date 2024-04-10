#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y;
string s1,s2;

int main(){
	ios::sync_with_stdio(0);
	cin>>s1>>s2;
	for(auto i:s1)x+=(i&1);
	for(auto i:s2)y+=(i&1);
	if(x&1)x++;
	cout<<((x>=y)?"YES":"NO");
}