#include<bits/stdc++.h>
using namespace std;
long long a[10010],u,id,G,Q;
long long left(long long x){
	if (x==1) return 3;return x-1;
}
long long useless(long long x,long long y){
	if ((x==1)&&(y==2)) return 3;
	if ((x==1)&&(y==3)) return 2;
	if ((x==2)&&(y==3)) return 1;
	if ((x==2)&&(y==1)) return 3;
	if ((x==3)&&(y==1)) return 2;
	if ((x==3)&&(y==2)) return 1;
}
int main(){
	cin>>a[1]>>a[2]>>a[3];
	cout<<"First\n";
	cout<<"10000000000\n";
	cout.flush();
	cin>>id;a[id]+=10000000000;u=a[id]*2-a[id % 3+1]-a[left(id)];
	cout<<a[id]*2-a[id % 3+1]-a[left(id)]<<endl;
	cin>>G;a[G]+=u;Q=useless(G,id);
	cout<<a[id]-a[Q]<<endl;
	return 0;
}