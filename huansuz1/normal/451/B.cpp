#include<iostream>
#include<algorithm>

using namespace std;

int x,y,n,p,t ,z, a[123456],b[123456] ,c[123456], mi=123456, ma=-1;

int main(){
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	for (int i=0; i<n; i++){
		if (a[i]!=b[i]){ p=i;
		if (p<=mi) mi=p;
		if (p>=ma) ma=p;}
	}
	 p=ma;
	for (int i=mi; i<=ma; i++)                               
		if (b[p]!=a[i]) {t=1; break; } else p--; 
	if (t==1) cout<<"no"; else 
	if (ma!=-1)	cout<<"yes"<<endl<<mi+1<<" "<<ma+1; else
	cout<<"yes"<<endl<<"1 1";
	
		
	return 0;          
}