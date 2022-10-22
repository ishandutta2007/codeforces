#include<bits/stdc++.h>
using namespace std;
int n,x;
void find(vector<int>&a,int o){
	int l,r;
	if(o&1)l=a[1],r=a[3];
	else l=a[0],r=a[2];
	while(l<=r){
		int mid=l+r>>1;
		int z=a[o];
		a[o]=mid;
		cout<<"? "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
		cin>>x;
		if(x){
			if(o&2)r=mid-1;
			else l=mid+1;
		}
		else{
			a[o]=z;
			if(o&2)l=mid+1;
			else r=mid-1;
		}
	}
}
vector<int>a,b,oa,ob;
int main(){
	cin>>n;
	a={1,1,n,n};
	b={1,1,n,n};
	find(a,0);
	find(b,2);
	if(a[0]<=b[2]){
		cout<<"? "<<a[0]<<" "<<1<<" "<<b[2]<<" "<<n<<endl;
		cin>>x;
		if(x){
			oa={1,3,0,2};
			ob={3,1,2,0};	
		}
	}
	if(!oa.size()){
		oa={0,2,1,3};
		ob={2,0,3,1};
	}
	a={1,1,n,n};
	b={1,1,n,n};
	for(int i=0;i<4;++i)find(a,oa[i]),find(b,ob[i]);
	cout<<"! ";
	for(int i=0;i<4;++i)cout<<a[i]<<" ";
	for(int i=0;i<4;++i)cout<<b[i]<<" ";
	return 0;
}