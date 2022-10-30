 #include <conio.h> 
 #include <iostream> 
 #include <math.h> 
 #include <map>
 using namespace std;
	int n,a[34567],m,z=1;
 int main()   {
 	cin>>n>>m;
 	for (int i=1; i<n; i++)
 		cin>>a[i];
 	while(z<m){
 	z=(a[z]+z);
 	}
 	if (z==m) cout<<"YES"; else cout<<"NO";


	
	return 0;
 }