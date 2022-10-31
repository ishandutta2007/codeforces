#include <iostream>
using namespace std;
 
int main() {
	int t, w, h, n, s, c1 = 0, c2 = 0, c3 = 0;
	cin>>t;
	
	for(int i = 0; i < t; i++){
		cin>>w>>h>>n;
		c1 = 1;
		while (w % 2 == 0){
		  	w /= 2;
		   	c1 = c1 * 2;
		}
		while (h % 2 == 0){
		   	h = h / 2;
		   	c1*=2;
		}
		if (c1 >= n) cout<<"YES"<<endl; else cout<<"NO"<<endl;    
		
		
	}
}