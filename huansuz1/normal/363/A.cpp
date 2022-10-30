#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;

ll n,z;
char a[12][12];

                      
int main(){
    for (int i=0; i<12; i++){
        a[i][0]='O';
        a[i][1]='-';
        a[i][2]='|';
        a[i][3]='-';
        a[i][4]='O';
        a[i][5]='O';
        a[i][6]='O';
        a[i][7]='O';
    }
    cin>>n;
    if (n==0){ cout<<"O-|-OOOO";  return 0;}
    while(n!=0){
        int k=n%10;
        n/=10;
        if (k>=5) {
            k-=5; 
            swap(a[z][0],a[z][1]); 
        }
        int p=3;
        while(k!=0){
            swap(a[z][p],a[z][p+1]);
            k--;
            p++;    
        }
        z++;
    }
    for (int i=0; i<z; i++){
        for (int j=0; j<8; j++)
            cout<<a[i][j];
        cout<<endl;
    
    }


    return 0;


}