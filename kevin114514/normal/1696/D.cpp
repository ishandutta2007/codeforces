#include <iostream>
#include<map>
#include <algorithm>
using namespace std;
#define N 550000
#define mod 1000000007
#define int long long 
int a[550000],lmin[N],lmax[N],rmin[N],rmax[N];
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		map<int,int> q;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		int minIdx=min_element(a,a+n)-a;
		lmin[0]=lmax[0]=0;
		for(int i=1;i<n;i++){
			if(a[i]<a[lmin[i-1]]) lmin[i]=i;
			else{
				lmin[i]=lmin[i-1];
			}
			if(a[i]>a[lmax[i-1]]) lmax[i]=i;
			else lmax[i]=lmax[i-1];
		}
		rmin[n-1]=rmax[n-1]=n-1;
		for(int i=n-2;i>=0;i--){
			if(a[i]<a[rmin[i+1]]) rmin[i]=i;
			else rmin[i]=rmin[i+1];
			if(a[i]>a[rmax[i+1]]) rmax[i]=i;
			else rmax[i]=rmax[i+1];
		}
		int id=minIdx;
		int ans=0;
		while(id){
			id=lmax[id];
			++ans;
			if(id==0) break;
			id=lmin[id];
			++ans;
		}
		id=minIdx;
		while(id!=n-1){
			id=rmax[id];
			++ans;
			if(id==n-1) break;
			id=rmin[id];
			++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}