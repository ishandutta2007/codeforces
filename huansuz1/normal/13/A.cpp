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
int n,s;
int func(int n,int k){
    int ans=0;
    while(n!=0){
        int p=n%k;
        n/=k;
        ans += p;
    }
    return ans;
}

int gcd(int a, int b) {
    while(a!=0){
        b=b%a;
        swap(a,b);  
    }
    return b;
}
int main() {
    cin>>n;
    for (int i=2; i<n; i++){
        int m=n;
        s+=func(m,i);
    }
    int p=gcd(s,n-2);
    cout<<s/p<<"/"<<(n-2)/p;
    return 0;
}