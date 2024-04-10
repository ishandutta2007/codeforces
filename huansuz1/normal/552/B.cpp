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
long long n,ans,k;

int main() {
    cin>>n;
    k=n;
    if (n<10 && k>0) {ans+=k*1; k=0;} else if (n>=10 && k>9) {ans+=9*1; k-=9;}
    if (n<100 && k>0) {ans+=k*2; k=0;} else if (n>=100 && k>90) {ans+=90*2; k-=90;}
    if (n<1000 && k>0) {ans+=k*3; k=0;} else if (n>=1000 && k>900) {ans+=900*3; k-=900;}
    if (n<10000 && k>0) {ans+=k*4; k=0;} else if (n>=10000 && k>9000) {ans+=9000*4; k-=9000;}
    if (n<100000 && k>0) {ans+=k*5; k=0;} else if (n>=100000 && k>90000) {ans+=90000*5; k-=90000;}
    if (n<1000000 && k>0) {ans+=k*6; k=0;} else if (n>=1000000 && k>900000) {ans+=900000*6; k-=900000;}
    if (n<10000000 && k>0) {ans+=k*7; k=0;} else if (n>=10000000 && k>9000000) {ans+=9000000*7; k-=9000000;}
    if (n<100000000 && k>0) {ans+=k*8; k=0;} else if (n>=100000000 && k>90000000) {ans+=90000000*8; k-=90000000;}
    if (n<1000000000 && k>0) {ans+=k*9; k=0;} else if (n>=1000000000 && k>900000000) {ans+=900000000ll*9; k-=900000000;}
    if (n==1000000000) ans+=(k*10);







    cout<<ans;

    return 0;
}