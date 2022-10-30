#include<iostream>
#include<string>
#include<algorithm>
  
using namespace std;
 
long long n,k,m,a[1200][1200],x,y,ans,o;
int main(){
	cin>>n>>m>>k;
    for (int i=0; i<k ;i++){
		cin>>x>>y;
		a[x][y]=1;
		if (a[x-1][y]==1 && a[x-1][y-1]==1 && a[x][y-1]==1 && o==0) {ans=i+1; o=1; }
		if (a[x-1][y]==1 && a[x-1][y+1]==1 && a[x][y+1]==1 && o==0) {ans=i+1; o=1; }
		if (a[x+1][y]==1 && a[x+1][y-1]==1 && a[x][y-1]==1 && o==0) {ans=i+1; o=1; }
		if (a[x+1][y]==1 && a[x+1][y+1]==1 && a[x][y+1]==1 && o==0) {ans=i+1; o=1; }
	}
	cout<<ans;

                                                                                          
return 0;
}