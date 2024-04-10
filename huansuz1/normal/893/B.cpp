#include <iostream>
using namespace std;
int rec(int m){
	int x=0,y=0,ans = m,z=0;
	while(m>0){
		//if (m%2==0 && x == y+1 && x>0) { cout<<x<<" "<<y<<" "<<ans<<endl; return 0; }
		if (m%2==0 && x){
			x=0;
			y=0;
			z++;
			
		}
		if (m%2) 
			x++;
		 else
			y++;
		m/=2;
	}
if (x == y+1 && z == 0) {cout<<ans; exit(0);}

	
}
 
int main() {
	int n, k, p;
	cin>>n;
	for (int i = n; i >= 1; i--)
		if (n % i == 0) rec(i);
		
	

	return 0;
}