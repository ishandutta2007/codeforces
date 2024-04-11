#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
long long b[200099],c[200099],n,m,ta,tb,k;
int main(){
	cin>>n>>m>>ta>>tb>>k;
	if(k>=n || k>=m){cout<<-1;return 0;}
	f(i,0,n){
		cin>>b[i];
		//scanf("I64d%",&b[i]);
		b[i]+=ta;
	}
	f(i,0,m){
		cin>>c[i];
		scanf("I64d%",&c[i]);
	}
	long long l=0,mx=0,p1=0,p2=0;
	while(p1<=k){
		if(b[p1]>c[p2]){
			p2++;
		}
		else{
			if(p2+(k-p1)>=m){
				cout<<-1;
				return 0;
			}
			mx=max(mx,c[p2+(k-p1)]);
			p1++;
		}
		if(p2>=m){
			cout<<-1;
			return 0;
		}
	}
	cout<<mx+tb;
}