#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,mi1,ma1,mi2,ma2,mi3,ma3;

int main(){
    cin>>n;
    cin>>mi1>>ma1;
    cin>>mi2>>ma2;
    cin>>mi3>>ma3;
    for (int i=ma1; i>=mi1; i--){
        int k=n-i;
        if (k>=mi2 && k-mi2>=mi3) {
            cout<<i<<" ";
            if ((mi2+(k-mi2-mi3))>ma2) cout<<ma2<<" "<<k-ma2;   else cout<<(mi2+(k-mi2-mi3))<<" "<<mi3;
            return 0;
        }  
    }

    return 0;
}