#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>i;
    	j=(-i&i);
    	j+=(i==j)+(i==1);
    	cout<<j<<'\n';
	}
}