#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b,c,d;
    cin>>a>>b>>c>>d;
    int z1=a+b,z2=b+c,z3=c+d,z4=a+d;
    if(z1==z3||z2==z4||a+c==b+d||z1+c==d||z1+d==c||z2+a==d||z2+d==a||z3+a==b||z3+b==a||z4+c==b||z4+b==c)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0;
}