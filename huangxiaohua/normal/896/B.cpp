#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k,l,r,a[1050],res,sb,md;

int main() {
	cin>>n>>t>>sb;
	md=(1+sb)/2;
	l=0;r=n+1;
	while(t--){
		cin>>k;
		if(k<=md){
			for(i=1;i<=l;i++){
				if(a[i]>k){
					a[i]=k;
					cout<<i<<endl;
					goto aaa;
				}
			}
			cout<<l+1<<endl;
			a[++l]=k;
		}
		else{
			for(i=n;i>=r;i--){
				if(a[i]<k){
					cout<<i<<endl;
					a[i]=k;goto aaa;
				}
			}
			cout<<r-1<<endl;
			a[--r]=k;
		}
		aaa:;
		if(l==r-1)return 0;
	}
	return 1;
}