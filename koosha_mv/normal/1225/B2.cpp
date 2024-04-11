#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
long long q,n,k,d,p1,p2,m,mn,a[200099];
int main(){
	cin>>q;
	f(salam,0,q){
		cin>>n>>k>>d;
		map <int,int> mark;
		p1=0,p2=0,m=0,mn=1e9;
		f(i,0,n)
			scanf("%I64d",&a[i]);
		f(i,0,d){
			if(mark[a[p2]]==0)
				m++;
			mark[a[p2]]++;	
			p2++;
		}
		mn=m;
		while(p2<n){
			if(mark[a[p1]]==1)
				m--;
			mark[a[p1]]--;
			p1++;
			if(mark[a[p2]]==0)
				m++;
			mark[a[p2]]++;
			p2++;
			mn=min(mn,m);
		}
		while(p1<n){
			mark[a[p1]]--;
			p1++;
		}
		//cout<<salam<<" : "<<endl;
		//f(i,0,10){
		//	cout<<mark[i];
		//}
		//cout<<endl;
		cout<<mn<<endl;
	}
}