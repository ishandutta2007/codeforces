#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;
 int a[123][123],n,b[123],z;
 
 int main(){
 cin>>n;
 for (int i=0; i<n; i++)
    for (int j=0; j<n; j++){
        cin>>a[i][j];       
 }
 for (int i=0; i<n; i++)  {
    int p=0;

    for (int j=0; j<n; j++)
        if (a[i][j]==1 || a[i][j]==3 || a[j][i]==2 || a[j][i]==3) {p=1; break;}  
    if (p==0) b[z++]=i+1;
 }
 cout<<z<<endl;
 for (int i=0; i<z; i++)
    cout<<b[i]<<" ";


    return 0;
 }