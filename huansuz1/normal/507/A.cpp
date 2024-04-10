 #include <conio.h> 
 #include <iostream> 
 #include <math.h> 
 #include <map>
 using namespace std;
	
int q,z;
int a[1234],n,k,b[1234];
 int main()   {
 	cin>>n>>k;
 	for (int i=0; i<n; i++) {
 		cin>>a[i];           
 		b[i]=i+1;	
 	}
 	for (int i=0; i<n; i++)   
 		for (int j=0; j<n; j++)
 			if (a[i]<a[j]) {swap(a[i],a[j]); swap(b[i],b[j]);}
 	int z=1,s=a[0];
 	if (s>k) {cout<<0; return 0;}
 	while(s<=k && z!=n+1){
 		s+=a[z++];
 	}
 	cout<<z-1<<endl;
 	for (int i=0; i<z-1; i++)
 		cout<<b[i]<<" ";

	
	return 0;
 }