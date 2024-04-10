#include<iostream>
#include<string>
#include<algorithm>
  
using namespace std;
 
int a[1234],n,p=-1,z,k;
int main(){
	cin>>n;
	for (int i=0; i<n; i++){
			cin>>a[i];
			if (a[i]==1 && k==0){ p=i; k=1; }
	}
	if (p==-1) {cout<<0; exit(0);}
	for (int i=p; i<n; i++){
		if (a[i]==1) z++; else {
			k=0;
			for (int j=i; j<n; j++)
				if (a[j]==1) {i=j-1; k=1; z++;break;}

			if (k==0) { cout<<z; exit(0);}
		}
	}
	cout<<z;
	

                                                                                          
return 0;
}