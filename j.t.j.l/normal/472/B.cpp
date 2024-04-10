#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,m,i,x,a[3000];
	cin>>n>>m;
	for (i=0;i<n;i++){
	//	scanf("%d",&a[i]);
		cin>>a[i];
	}
	int ans=0;
	sort(a,a+n);
	n--;
	while (n>-1){
		ans+=2*(a[n]-1);
		n-=m;
	}
	cout<<ans<<endl;
	return 0;
}