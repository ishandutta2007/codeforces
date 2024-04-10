#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,a[66];

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	n-=3;
    	a[1]=n/3;n-=a[1];
    	a[2]=n/2;n-=a[2];
    	a[3]=n;
    	sort(a+1,a+4);
    	a[3]+=2;
    	a[2]+=1;
    	cout<<a[2]<<' '<<a[3]<<' '<<a[1]<<endl;
	}
}