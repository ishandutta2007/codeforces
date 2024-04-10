#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>                         
#include <cmath>
#include <map>
#include <set>

using namespace std;

map<int, int> mp;
int n,m,b[123][123],d[1245],a[1234],c[1234],e[1234],p,k,z,ma,zz,zzz;


int main(){
	cin>>n>>k;
	for (int i=1; i<=k; i++)  {
	    cin>>a[i]; e[i]=a[i];            
		d[a[i]]=1;
	}

	    sort(a+1,a+k+1);    
	p=k;
	for (int i=1; i<=k; i++){ 
	    c[i]++;
	    b[i][c[i]]=a[i];     
	    
	    }
	for (int i=1; i<=n*k; i++)
	{	if (d[i]!=1){c[p]++; b[p][c[p]]=i; p--;}
				if (p==0) p=k;
	
	}    
	
	for (int i=1; i<=k; i++)	{
		for (int j=1; j<=k; j++)
			if (b[j][1]==e[i])  {
		for (int o=1; o<=c[j]; o++)
			cout<<b[j][o]<<" ";  
		cout<<endl;		
		break;
	}
		                         }

	return 0;

}