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

string s;
int x=-1,y=-1,xx=-1,yy=-1;

int main(){
    cin>>s;
    for (int i=0; i<s.length(); i++){
        if (s[i]=='A' && s[i+1]=='B' && x==-1) {x=i;   } 
        if (s[i]=='B' && s[i+1]=='A' && y==-1) {y=i;   } 
    }
    for (int i=s.length()-2; i>=0; i--){
        if (s[i]=='A' && s[i+1]=='B' && xx==-1) {xx=i;  } 
        if (s[i]=='B' && s[i+1]=='A' && yy==-1) {yy=i;  } 
    }
    if ((abs(x-y)>=2 && x>=0 && y>=0) || (abs(x-yy)>=2 && x>=0 && yy>=0) || (abs(xx-y)>=2 && xx>=0 && y>=0) || (abs(xx-yy)>=2 && xx>=0 && yy>=0) )   {cout<<"YES"; return 0;}
    cout<<"NO";


    
        


    return 0;
}