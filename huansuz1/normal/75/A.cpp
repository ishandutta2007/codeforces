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

int s,l;
int x,y,z,w,p,t;

int main() {
    cin>>s>>l;
    w=s+l;
    z=1;
    while(s!=0){
    	if (s%10!=0) {x+=(s%10)*z; z*=10;}
    	s/=10;	
    }
    z=1;
    while(l!=0){
    	if (l%10!=0) {y+=(l%10)*z; z*=10;}
    	l/=10;	
    }
    
    z=1;
    while(w!=0){
    	if (w%10!=0) {p+=(w%10)*z; z*=10;}
    	w/=10;	
    }
    
   if (p==x+y) cout<<"YES"; else cout<<"NO";


    
    
    return 0;
}