#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)))

int i,j,k,n,m,t,res,ans,tmp,md,sb;

void ask(int l,int r,int n){
	if(l==r){
		cout<<"! "<<l<<endl;
		//cout<<" !! "<<ans;
		exit(0);
	}
	md=(l+r+1)/2;
	k=(n-md%n);
	if(k==n)exit(1);
	cout<<"+ "<<k<<endl;
	
	cin>>sb;
	//ans+=k;sb=ans/n;
	
	if(sb==((md+n-1)/n)){
		ask(md+k,r+k,n);
	}
	else{
		ask(l+k,md-1+k,n);
	}
}

int main() {
	//ios::sync_with_stdio(0);
	cin>>n;
	ask(0,n-1,n);
}