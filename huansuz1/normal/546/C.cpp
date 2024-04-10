#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;

int k,n,w,a[400001],s,ans,x,y,b[400003];
map<int,int> ma;
                      
int main(){
    cin>>n;
    cin>>x;
    for (int i=1; i<=x; i++)
        cin>>a[i];
    cin>>y;
    for (int i=1; i<=y; i++)
        cin>>b[i];
    int i=1,j=1;
    
    while(i!=0){
        if (a[i]>b[j]) {x++; a[x]=b[j]; x++; a[x]=a[i];} else 
                       {y++; b[y]=a[i]; y++; b[y]=b[j];}
        if (j>y) {cout<<ans<<" "<<1; return 0;}     
        if (i>x) {cout<<ans<<" "<<2; return 0;}
        if (ans==100000) {cout<<-1; return 0;}


        j++;
        i++;
        ans++;

    }


    return 0;


}