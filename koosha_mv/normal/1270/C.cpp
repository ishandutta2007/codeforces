#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,t,a[72],p1,tvn,add,sum,x;
int an(int x,int y){
	if(x!=y) return 1;
	return 0;
}
int main(){
	cin>>t;
	f(q,0,t){
		f(i,0,71) a[i]=0;
		cin>>n;sum=0;
		f(i,0,n){
			cin>>x;
			sum+=x;p1=0;
			while(x>0){
				a[p1]=an(a[p1],x%2);
				p1++;
				x/=2;
			}
		}
		tvn=1;add=0;
		f(i,0,70){
			add+=tvn*a[i];
			tvn*=2;
		}
		cout<<2<<endl;
		cout<<add<<" "<<sum+add<<endl;
	}
}