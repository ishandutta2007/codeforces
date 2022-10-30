#include<iostream>
#include<string>
#include<algorithm>
  
using namespace std;
 
long long n,m,k,x,a[1234][123],z,p,ans;
int main(){
    cin>>n>>m>>k;
    for (int i=0; i<=m; i++){
		cin>>x;
		p=0;
		while(x!=0){
			if (x%2==1) a[i][p]=1;
			x/=2;
			p++;
		}
	}
	for (int i=0; i<m; i++){
		z=0;
		for (int j=0; j<n; j++)
			if (a[i][j]==a[m][j]) z++;
		if (n-z<=k) ans++;
	}
		
	cout<<ans;

                                                                                          
return 0;
}