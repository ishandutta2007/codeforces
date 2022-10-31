#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;

 int n,m,q,k,a[1234][1234],b[1234],c[1234],x,y,ma,p;


 int main(){
 cin>>n>>m>>q;
 for (int i=1; i<=n; i++){ 
    int z=0;
    for (int j=1; j<=m; j++) {
        cin>>a[i][j];         
        if (a[i][j]==1) z++; else {
            c[z]++;
            z=0;
        }
    }
    c[z]++;
                       
    
 }


 for (int i=0; i<q; i++){
    cin>>x>>y;
        int j=y-1,z=0;
        while(j!=0){
            if (a[x][j]!=1) break; else z++;
            j--;
        }
        j=y;int zz=0;
        while(j!=m){
            j++;
            if (a[x][j]!=1) break; else zz++;
        }
        if (a[x][y]==1) {a[x][y]=0; c[zz+z+1]--; c[z]++; c[zz]++;} else 
            {a[x][y]=1; c[zz+z+1]++; c[z]--; c[zz]--;}
        p=0;
        for (int j=500; j>=1; j--)
            if (c[j]!=0) {cout<<j<<endl; p=1; break;}
        if (p==0) cout<<0<<endl;


 }

    return 0;
 }