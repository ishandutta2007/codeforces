#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
int  n,m,a[12345],k,z,x,zz;
map<int,int> b;
int main(){
	cin>>n>>k;
	for (int i=0; i<n; i++){
		cin>>a[i];
		b[a[i]]=1;
	}
	
	cin>>m;
	for (int i=0; i<m; i++){
		cin>>x;
		z=123;
		for (int j=n-1; j>=0; j--){
			if (x/a[j]>k) break;
			int y=x;
			int p=0;
			for (int o=1; o<=k; o++){
				y-=a[j];
				if (y<0) break;
				if (y==0)  {  z=min(z,o); break;}
			
				for (int i1=1; i1<=k-o; i1++)
					if (y%i1==0 && b[y/i1]==1) {z=min(o+i1,z);break;}
		
			}
				
		}
		
		if (z!=123) cout<<z<<endl; else cout<<-1<<endl;
	}

	return 0;
}