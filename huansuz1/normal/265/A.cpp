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


string s,l;
int z;

int main(){
    cin>>s>>l;
    for (int i=0; i<l.length(); i++){
        if (l[i]==s[z]) z++;
    }
    cout<<z+1;



    return 0;
}