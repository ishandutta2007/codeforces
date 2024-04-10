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

int n,b[10723677],z,m,x,y,N=10000000;
bool ok[12345678];
ll a[19999999];

int main(){
    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d",&m);              
        b[m]++;
    }
    for (int i = 2; i <= N; i++)  
        if (!ok[i]){
            for (int j = i; j <= N; j += i) {
                a[i] += 1ll * b[j];
                ok[j] = 1;             
            }
        }
    
    m=0;
    for (int i=2; i<=N; i++) 
        a[i]+=a[i-1];        
    cin>>m;
    for (int ii=0; ii<m; ii++){
        scanf("%d%d",&x,&y);
        if (x>N) x=N;
        if (y>N) y=N;
        cout<<a[y]-a[x-1]<<endl;
    }
    



    return 0;
}