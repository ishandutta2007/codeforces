#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll n,t,a[200009],ans=0;
void divide(int x,int y)
{
	if(x==y) return ;
	int mid=(x+y)/2;
	divide(x,mid);divide(mid+1,y);
	int l=x,r=mid+1;
	while(l<=mid&&r<=y)
	{
		if(a[l]+t<=a[r])
			l++;
		else
		{
			ans+=mid-l+1;
			r++;
		}
	}
	sort(a+x,a+y+1);
}
 
int main(){
	cin>>n>>t;
	f(i,2,n+2){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	divide(1,n+1);
	cout<<ans;
}