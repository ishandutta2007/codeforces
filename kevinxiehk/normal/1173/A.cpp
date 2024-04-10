#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b,c;
    cin>>a>>b>>c;
    a-=b;
    int t1=a+c;
    int t2=a-c;
    if(t1>0&&t2>0)cout<<"+"<<endl;
    else if(t1==0&&t2==0)cout<<"0"<<endl;
    else if(t1<0&&t2<0)cout<<"-"<<endl;
    else cout<<"?"<<endl;
	return 0;
}