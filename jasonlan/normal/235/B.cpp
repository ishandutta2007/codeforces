#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	double x1=0,x2=0,rst,ans=0;
	for(int i=1;i<=n;++i){
		cin>>rst;
		ans+=(2*x1+1)*rst;
		x1=(x1+1)*rst;
	}
	printf("%.10lf\n",ans);
	return 0;
}