#include<bits/stdc++.h>
using namespace std;
struct node{int l,r;}p[610];
int n,l,r,x,c;
string s;
int main(){
	for(cin>>n,x=1;n--;)for(cin>>l>>r,p[++c]={l+x,r+x},s+='(',++x;c&&x>=p[c].l&&x<=p[c].r;++x,--c,s+=')');
	cout<<(c?"IMPOSSIBLE":s);
}