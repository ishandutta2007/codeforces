#include<iostream>
#include<algorithm>
using namespace std;
int n,k,i,sum,b;

struct A{
	int p,d;
}a[105];

struct A_sort{
	bool operator()(A q,A w) {
		if(q.d<w.d){return true;}
		return false;
	}
};

int main()
{
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a[i].d;
		a[i].p=i+1;
	}
	sort(a,a+n,A_sort());
	for(i=0;i<=n;i++){
		if(sum>k){b=i-1;break;}
		if(i==n){b=n;break;}
		sum+=a[i].d;
	}
	cout<<b<<"\n";
	for(i=0;i<b;i++){
		cout<<a[i].p<<" ";
	}
}