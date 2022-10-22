#include <iostream>
using namespace std;
long duzina[1000000];
int main(){
    long n,tren=0,ziv=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>duzina[i];}
    for(i=n-1;i>=0;i--){
        if(tren==0)ziv++;
        tren--;
        tren=max(tren,duzina[i]);
    }
    cout<<ziv;
	return 0;
}