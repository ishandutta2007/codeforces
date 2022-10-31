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

map<int,int> st,ss;
map<int,int> :: iterator it;
int n, x,k,y,t,xx,yy,c,b,ans,a[123123];
char ch;

int main() {
    cin>>n>>k;
    for (int i=0; i<k; i++) {
        cin>>x;
        ans+=x-1;
        int p=0;
        t=0;
        for (int i=0; i<x; i++){
            cin>>y;
            if (y-1==p && t==0) p++; else t=1;
        }
        if (p>=1) {t=1;ans-=(p-1)*2; xx=p;}
    }
    ans+=n-1;
    if (k==1) {cout<<0; return 0;}
    cout<<ans;
    return 0;
}