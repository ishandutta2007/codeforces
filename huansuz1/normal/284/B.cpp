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


int n,a,i,x,y;
char q;

int main(){
    cin>>n;
    for (int i=0; i<n; i++) {
    	cin>>q;
    if (q=='A')  a++; else
    	if (q=='I')	y++;
    }
    if (y==0) cout<<a; else
    if (y==1) cout<<1; else
    cout<<0;


    return 0;
}