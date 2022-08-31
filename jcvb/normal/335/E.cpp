#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef double db;
int main(){
	string str;
	cin>>str;
	int n,h;scanf("%d%d",&n,&h);
	if(str=="Bob")printf("%d\n",n);
	else{
		db ans=n;
		for (int i=1;i<=h;i++){
			for (int j=1;j<=n-1;j++)
				ans+=(n-j)*pow(2,-i*2)*pow(1-pow(2,-i),j-1)*(pow(2,i)-pow(2,i-1)*(1+(j-1)/(pow(2,i)-1)));
		}
		printf("%.9lf\n",ans);
	}
	return 0;
}