#include <iostream>
using namespace std;
char a[3];
char b[3];
int main() {
int n,i,moze1=0,moze2=0;
    cin>>a;
    cin>>n;
for(i=0;i<n;i++){
    cin>>b;
if(a[0]==b[0] && a[1]==b[1]){cout<<"YES";return 0;}
    if(b[0]==a[1])moze2=1;
    
if(a[0]==b[1])moze1=1;
}
    if(moze1==1 && moze2==1)cout<<"YES";
else cout<<"NO";
	return 0;
}