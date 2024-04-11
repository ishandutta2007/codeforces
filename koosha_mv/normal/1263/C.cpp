#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
ll s,n,t,k;
float r,r2;
ll l,x,a[200000],tagh;
int main(){
	cin>>t;
	f(i,0,t){
		cin>>n;
		s=1;tagh=n;
		k=0;
		while(tagh>0){
			k++;
			a[s]=(n/tagh);s++;
			//cout<<a[s-1]<<" "<<tagh<<endl;
			//r=(n/tagh);
			//r2=(tagh*a[)/(a[s-1]+1);
			tagh=n/(a[s-1]+1);
		}
		cout<<s<<endl;
		f(j,0,s){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
}