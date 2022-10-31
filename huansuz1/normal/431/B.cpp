#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
  
  
#define sz 20
#define N 1299721   
#define ll long long
   
using namespace std;
  
int n, ok[sz], z,a[12][12],b[12],c[123];
long long ma;  

void rec(int v) {
    if (v >= 6) {
    long long s=(a[b[1]][b[2]]+a[b[2]][b[1]]+a[b[3]][b[4]]+a[b[4]][b[3]])+(a[b[2]][b[3]]+a[b[3]][b[2]]+a[b[4]][b[5]]+a[b[5]][b[4]])+(a[b[3]][b[4]]+a[b[4]][b[3]])+(a[b[4]][b[5]]+a[b[5]][b[4]]);	
    if (s>ma) ma=s;
    } else {
        for (int i = 1; i <= 5; i++)
            if (!ok[i]) {
                ok[i] = 1;
                b[v] = c[i];
                rec(v + 1);
                ok[i] = 0;
            }
    }   
}
  
int main()
{
    for (int i=1; i<=5; i++)   {
    	for (int j=1; j<=5; j++)
    		cin>>a[i][j];
    	c[i]=i;      
    }
      
    rec(1);
    cout<<ma;
  
    return 0;
}