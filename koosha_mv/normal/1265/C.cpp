#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int j,g,s,b,x,t,n,gh=-1,a[400009],sa=-1,l;
int main(){
	cin>>t;
	f(lol,0,t){
		cin>>n;l=0;gh=-1;sa=-1;a[0]=0;
		f(i,0,n){
			cin>>x;
			if(x==gh){
				a[sa]++;
			}
			else{
				sa++;a[sa]=1;}
			
			gh=x;
		}
		g=a[0],s=0,b=0,j=1;
		while(j<=sa && s<=g){
			s+=a[j];
			j++;
		}
		while(j<=sa && g+b+s+a[j]<=n/2){
			b+=a[j];
			j++;
		}
		if(g<b && g<s)
			cout<<g<<" "<<s<<" "<<b<<endl;
		else
			cout<<0<<" "<<0<<" "<<0<<endl;
	}
}