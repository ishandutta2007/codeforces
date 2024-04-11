#include <bits/stdc++.h>
#include<map>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
int a[200099];
int main(){
	int n;string s;cin>>n;
	f(i,0,n){
		cin>>a[i];
	}
	cin>>s;
	s[n-1]='0';
	int mx=0,mn=1e9,y=-1,p1=0,p2=0;
	while(p1<n && p2<n){
		//cout<<"P2:"<<p2<<endl;
		//cout<<p1<<" "<<p2<<" "<<mn<<" "<<mx<<endl;
		if(s[p2]=='0'){
			mx=max(mx,a[p2]);
			mn=min(mn,a[p2]);
			
			//cout<<"salam";//cout<<p1<<" "<<p2<<" "<<mn<<" "<<mx<<endl;
			if(mn<p1+1 || mx>p2+1){
				//cout<<p1<<" "<<p2<<endl;
				cout<<"NO";return 0;}
			p1=p2+1;p2=p1;
			mx=0,mn=1e9;
		}
		while(s[p1]=='0'){
			if(a[p1]!=p1+1){
				cout<<endl<<"NO";
				return 0;
			}
			p1++,p2=p1;
		}
		mx=max(mx,a[p2]);mn=min(mn,a[p2]);
		p2++;
	}
	cout<<"YES";
}