#include<iostream>
#include<algorithm>

using namespace std;

int x,y,n,p,m,t ,z, a[123][123],b[123][123];

int main(){
    cin>>n>>m;
    for (int i=0; i<n; i++){
    	cin>>x;
    	z=0;
    	while(x!=0){
    	if (x%10==7 || x%10==4) z++;
    	x/=10;
    	}
    	if (z<=m) y++;
    }
    cout<<y;
 	
 	
 	
 	
 	
 	
 	
 	return 0;          
}