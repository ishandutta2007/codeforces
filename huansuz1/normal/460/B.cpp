#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;
long long n,m,a,b,c,x;
int z,ar[123];





int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
	cin>>a>>b>>c;
	for (int i=1; i<=90; i++){
		long long s=1;
	    for (int j=1; j<=a; j++)
	    	s*=i;
	    long long an=b*s+c,ans=an;
	    s=0;

	    while(an!=0){
	    	s+=an%10;
	    	an/=10;
	    }
	    if (s==i && ans>0 && ans<1000000000) {ar[z++]=ans;}
	}
	cout<<z<<endl;
	for (int i=0; i<z; i++)
		cout<<ar[i]<<" ";

					


}