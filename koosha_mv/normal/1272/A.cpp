#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll q,b,c;
ll a[4];
int main(){
	cin>>q;
	f(sal,0,q){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[0]==a[1] && a[1]==a[2]){cout<<0<<endl;}
		else {
		if(a[0]==a[1]){ a[0]++;a[1]++;
			if(a[2]>a[1]) a[2]--;
		}
		else{
			if(a[1]==a[2]){
				a[1]--;
				a[2]--;
				if(a[0]<a[1])
					a[0]++;
			}
			else{
				a[2]--;
				a[0]++;
			}
		}
		cout<<(a[2]-a[1])+(a[2]-a[0])+(a[1]-a[0])<<endl;
		}
	}
}