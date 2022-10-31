#include <algorithm>
#include <iostream>
#include <cstring>                                               
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

int n,m,x[255456],y[255432];
int a[1234][1234],b[1235],c[12],z,p,k=0;
int main(){
	cin>>n>>m;
	if (m==0 && n>2) { cout<<"No"; return 0;}
	if (m==0 && n==2) {cout<<"Yes"<<endl<<"ac"; return 0;}

	for (int i=0; i<m; i++) {
		cin>>x[i]>>y[i];
		a[x[i]][x[i]]=1;
		a[y[i]][y[i]]=1;          
		a[x[i]][y[i]]=1;
		a[y[i]][x[i]]=1;                            

	}
	for (int i=1; i<=n; i++) 
		if (b[i]==0) {
			z++;
			b[i]=z;
			k=0;
			for (int j=1; j<=n; j++) 
				if (b[j]==0) {
					int p=0;
					for (int o=1; o<=n; o++)
						if (a[i][o]!=a[j][o]) { p=1; break; }	
					if (p==0) b[j]=z;
				}
	    }
	if (z>3) {cout<<"No"; return 0;}
	 
	
	cout<<"Yes"<<endl;    
	p=-1;
	for (int i=1; i<=n; i++) {
		c[1]=0;	c[2]=0;	c[3]=0;
		for (int j=1; j<=n; j++)
			if (a[i][j]==1 && b[i]!=b[j]) c[b[j]]=1;
		if (c[1]+c[2]+c[3]==2) { p=b[i]; break; }
	} 
			
	string s=" acb";
	if (p==1) s=" bac"; else 
	if (p==2) s=" abc"; else 
	if (p==3) s=" acb"; 

	for (int i=1; i<=n; i++)
		cout<<s[b[i]];


    return 0;             
}