#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>

#define ll long long
#define f first
#define s second
#define mp make_pair

using namespace std;
queue < int > q;
string s[1235];
int n,k,al,bo,z,m,e,b[123456],x,y;


int main() {
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>b[i];
    if (n==1) {cout<<"1 0"; return 0;}
    if (n==2) {cout<<"1 1"; return 0;}
    x=1; y=n;
    al=b[1];
    bo=b[n];
    while(y-x>1){
        if (al<bo) {x++; al+=b[x];} else 
            if (al>bo) {y--; bo+=b[y];} else 
                if (al==bo && y-x>1) {y--; bo+=b[y]; x++; al+=b[x];} else 
                    if (al==bo && y-x==1) {x++; al+=b[x];}
    }
    cout<<x<<" "<<n-x;
    return 0;
}