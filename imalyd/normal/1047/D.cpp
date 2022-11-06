//Problem D
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
#define ll long long
ll n,m;
ll solve(ll a,ll b){
    if(a==1)return 3-llabs(b%6-3);
    if(a==2){
		if(b==2)return 4;
		if(b==3||b==7)return 2;
		return 0;
	}
	return a&b&1;
}
int main(){
    //for(int i=0;i<6;i++){for(int j=0;j<6;j++)cout<<solve(i,j);cout<<endl;}
    cin>>n>>m;if(n>m)swap(n,m); 
    cout<<n*m-solve(n,m);
    return 0;
}