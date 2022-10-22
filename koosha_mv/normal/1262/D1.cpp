#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int a[190],b[190];
int main(){
	int y,x,n,m,pos;
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	cin>>m;
	int l,tl=0,p;
	f(sa,0,m){
		cin>>x>>pos;
		tl=0;
		l=a[n-x];
		p=n-x;
		while(a[p]==l){
			tl++;
			p++;
		}
		f(i,0,n){
			if(b[i]>l)
				pos--;
			if(b[i]==l && tl>0){
				tl--;
				pos--;
			}
			if(pos==0){
				cout<<b[i]<<endl;
				break;
			}
		}
	}
}