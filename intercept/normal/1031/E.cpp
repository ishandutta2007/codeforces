#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n;
int a[M];
vector<vector<int>>ans;
int b[3];
int bit[M];
void add(int x,int v){
	for(;x<=n;x+=x&-x)bit[x]+=v;
}
int ask(int x,int rex=0){
	for(;x;x-=x&-x)rex+=bit[x];
	return rex;
}
int kth(int k,int y=0){
	for(int i=1<<20;i;i>>=1)
		if(y+i<n&&bit[y+i]<k)k-=bit[y+=i];
	return y+1;
}
void change(int x){
	add(x,-a[x]);
	a[x]^=1;
	add(x,a[x]);
}
void upd(int x,int y,int z){
	ans.eb(vector<int>{x,y,z});
	change(x);
	change(y);
	change(z);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		b[i%3]^=a[i];
	}
	if(b[0])b[1]^=1,b[2]^=1;
	if(b[1]&&n<7){
		cout<<"NO\n";
		return 0;
	}
	if(b[2]&&n<8){
		cout<<"NO\n";
		return 0;
	}
	for(int j=1;j<=5000;++j){
		for(int i=j*3;i<=n;++i){
			if(a[i]&&a[i-j]&&a[i-2*j]){
				ans.eb(vector<int>{i-2*j,i-j,i});
				a[i]=a[i-j]=a[i-j*2]=0;
			}
		}
	}
	
	for(int i=1;i<=n;++i)add(i,a[i]);
	for(int i=n;i>3;--i){
		if(a[i]){
			int x=ask(i);
			if(x>=3){
				int z=kth(x-1);
				if(a[z]&&z-(i-z)>=1&&a[z-(i-z)]){
					upd(z-(i-z),z,i);
					continue;
				}
				int y=kth(x-2);
				if(y-(i-y)>=1){
					upd(y-(i-y),y,i);
				}
				else {
					int x=i%3;
					if(x==0)x=3;
					int l=(i-x)/3;
					upd(x+l,x+l*2,i);
					if(a[x+l*2])upd(x,x+l,x+l*2);
				}
			}
			else{
				int x=i%3;
				if(x==0)x=3;
				int l=(i-x)/3;
				upd(x+l,x+l*2,i);
				upd(x,x+l,x+l*2);
			}
		}
	}
	if(a[3])upd(1,2,3);
	if(a[1]){
		upd(1,4,7);
		upd(4,5,6);
		upd(5,6,7);
	}
	if(a[2]){
		upd(2,5,8);
		upd(5,6,7);
		upd(6,7,8);
	}
	cout<<"YES\n";
	cout<<ans.size()<<"\n";
	for(auto o:ans){
		cout<<o[0]<<" "<<o[1]<<" "<<o[2]<<"\n";
	}
	return 0;
}