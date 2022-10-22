#include<iostream>
using namespace std;
int t3(int x)
{
	if(x<0)
		return 0;
	return x;
}
int main(){
	int n,m;
	cin>>n>>m;
	int x=0,minn=0,maxx=0,k;for(int i=0;i<n;i++){cin>>k;x+=k;minn=min(minn,x);maxx=max(maxx,x);}cout<<t3(m-(maxx-minn)+1);
	}