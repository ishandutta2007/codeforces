#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;
 int k;
 string s,l;


 int main(){
 cin>>s>>k;
 
 if (s.length()%k!=0) {cout<<"NO"; return 0;}
    k=s.length()/k;
    s+='0';

    for (int i=0; i<s.length(); i++){
        if (i%k==0 && i!=0){
            int y=l.length(),p=1;
            for (int j=0; j<l.length()/2; j++){
                y--;
                if (l[j]!=l[y]) {p=0; break;}
            }
            l="";
            if (p==0) { cout<<"NO"; return 0;}
        }
        l+=s[i];

    } 
    cout<<"YES";
    return 0;
 }