#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k,sb;

int main() {
	cin>>sb;
		for(i=1;i<=2000;i++){
			for(j=1;j+1005<=i;j++){
				if(!((sb+i)%j)){
					cout<<i<<endl;
					sb=(sb+i)/j;
					for(k=1;k<j;k++){
						printf("0 ");
					}
					printf("-1 ");
					for(k=j+1;k<=i;k++){
						printf("%d ",min(sb,1000000));
						sb=max(0,sb-1000000);
					}
					return 0;
				}
			}
		}
}