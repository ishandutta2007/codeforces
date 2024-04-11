#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,a,b,mid,t;
int ask(int p) {
	cout <<"? "<<p<< endl;
	cin >> a;
	cout <<"? "<<p+n<<endl;
	cin >> b;
 	if (a == b) {
 		cout << "! " << p << endl;
		exit(0);
  	}
  	return a<b;
}
int main(){
	cin>>n;
	if(n%4==2){cout<<"! -1";return 0;}
	ll l=1,r=n/2+1;n/=2;
	t=ask(1);
	while(l+1<r){
		mid=(l+r)/2;
		if(ask(mid)==t){
			l=mid;	
		}
		else{
			r=mid;
		}
	}
	cout<<"! "<<l<<endl;
}