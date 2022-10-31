#include<iostream>
using namespace std;
int x,y,n;
int main(){
cin>>n>>x>>y;
n/=2;
if ((x==n || x==n+1 )  && (y==n || y==n+1 )) cout<<"NO"; else cout<<"YES";



}