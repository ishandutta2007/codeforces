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
int n,l,r,x,k=0;
int ar[12];
string s;
int main(){
    cin>>s;
    while(k<=10000000){
        int p=0;
        p=k;
        if (p!=0) {
            int z=0;
            while(p!=0){    
                ar[z++]=p%10;
                p/=10;
            }
            z--;
            for (int i=0; i<s.length(); i++){
                if ((s[i]-'0')==ar[z]) z--;
                if (z==-1) {cout<<"YES"<<endl<<k; return 0;}
            }
        } else {
                for (int i=0; i<s.length(); i++)
                    if (s[i]=='0') {cout<<"YES"<<endl<<0; return 0;}
        }
        k+=8;
    }
    cout<<"NO";
    

    
        


    return 0;
}