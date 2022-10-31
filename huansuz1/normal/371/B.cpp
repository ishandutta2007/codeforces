#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>

#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;

int a[1234][1234],n,m,x,z,ans,b1[1234],b2[1234],c1,c2;
map <int,int> M1,M2;
queue<int> q;

int main(){
    cin>>n>>m;
    q.push(n);  
    M1[n]=1;
    while(!q.empty()){
        x=q.front();
        q.pop();
        if (x%2==0 && M1[x/2]==0) {q.push(x/2);M1[x/2]=M1[x]+1;}
        if (x%3==0 && M1[x/3]==0) {q.push(x/3);M1[x/3]=M1[x]+1;}
        if (x%5==0 && M1[x/5]==0) {q.push(x/5);M1[x/5]=M1[x]+1;}
    }
    q.push(m);
    M2[m]=1;
    while(!q.empty()){
        x=q.front();
        q.pop();
        if (M1[x]!=0 && M2[x]!=0) {cout<<M1[x]-1+M2[x]-1;return 0;}
        if (x%2==0 && M2[x/2]==0) {q.push(x/2);M2[x/2]=M2[x]+1;}
        if (x%3==0 && M2[x/3]==0) {q.push(x/3);M2[x/3]=M2[x]+1;}
        if (x%5==0 && M2[x/5]==0) {q.push(x/5);M2[x/5]=M2[x]+1;}
    }
    cout<<-1;
     

    return 0;
}