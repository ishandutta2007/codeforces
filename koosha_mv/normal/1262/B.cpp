#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int a[100099],c[100099];
int main(){
	int q,n;
	cin>>q;
	f(lo,0,q){
		int l=0,mark[100099]={0},p=1;
		cin>>n;
		f(i,0,n){
			cin>>a[i];
		}
		c[0]=a[0];
		mark[a[0]]=1;
		f(i,1,n){
			if(a[i]>a[i-1]){
				c[i]=a[i];
				mark[a[i]]=1;
			}
			else{
				while(mark[p]==1)
					p++;
				if(p>a[i])
					l=1;
				c[i]=p;
				mark[p]=1;
			}
		}
		if(l==1) cout<<-1;
		else{
			f(i,0,n){
				cout<<c[i]<<" ";
			}
		}
		cout<<endl;
	}
}