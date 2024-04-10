#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=101000;
int m,n,x;
bool vis[70];
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;++i){
		cout<<m<<endl;
		cin>>x;
		if(!x) 
			return 0;
		if(x>0) vis[i]=0;
		else vis[i]=1;
	}
	int l=1,r=m,mid,i=1;
	while(1){
		mid=l+r>>1;
		cout<<mid<<endl;
		cin>>x;
		if(!vis[i]) x=-x;
		if(!x) return 0;
		else if(x>0) l=mid+1;
		else r=mid-1;
		++i;
		if(i>n) i-=n;
	}
	return 0;
}