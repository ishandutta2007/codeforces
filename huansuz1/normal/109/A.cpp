#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
 
 
#define sz 20
 
using namespace std;
                                                                                              
int n, ok[sz],a[17],z;
string s;
 
 
int main()
{
    cin>>n;

    while(n>=0){
        if (n%7==0 && n>=0) {break;} 
        z++;
        n-=4;
        s+='4';
    }
    if (n<0) {cout<<-1; return 0;}    
    cout<<s;
    for (int i=0; i<n/7; i++)
        cout<<7;
 
    return 0;
}