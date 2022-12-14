#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c,i,d,x1,x2,y,ans;
int main(){
	cin>>a>>b>>c>>d;x1=b-a,x2=c-b;
	for(i=c;i<=d;++i){
		y=i-a-b;
		ans+=(x1+1)*(x2+1);
		if(y<0)continue;
		if(x1<x2)swap(x1,x2);
		if(y>=x1+x2)ans-=(x1+1)*(x2+1);
		else if(y>=x1)ans-=x2+1+(y-x1)*x1+(x1-y+x2+1)*(x1+y-x2)/2;
		else if(y>=x2)ans-=x2+1+(y+y-x2)*(x2+1)/2;
		else ans-=(y+2)*(y+1)/2;
	}cout<<ans;
}