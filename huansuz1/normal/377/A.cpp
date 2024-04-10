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

queue< pair < int , int > > q,qq;
int n,m,k,b[1234][1234],c[300344][2],z,x,y;
char a[1234][1234];
int main(){
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
            cin>>a[i][j];         
            if (a[i][j]=='.') {x=i; y=j;}
      }
    
    q.push(mp(x,y));
    b[x][y]=1;
    z++;
    c[z][1]=x;
    c[z][2]=y;
   while(!q.empty()){
        int i=q.front().f;
        int j=q.front().s;
        q.pop();
        if (a[i][j+1]=='.' && b[i][j+1]==0) {z++; b[i][j+1]=z; q.push(mp(i,j+1));c[z][1]=i; c[z][2]=j+1;}       
        if (a[i][j-1]=='.' && b[i][j-1]==0) {z++; b[i][j-1]=z; q.push(mp(i,j-1));c[z][1]=i; c[z][2]=j-1;}       
        if (a[i+1][j]=='.' && b[i+1][j]==0) {z++; b[i+1][j]=z; q.push(mp(i+1,j));c[z][1]=i+1; c[z][2]=j;}       
        if (a[i-1][j]=='.' && b[i-1][j]==0) {z++; b[i-1][j]=z; q.push(mp(i-1,j));c[z][1]=i-1; c[z][2]=j;}       
   }        
   if (k!=0) {
   for (int i=z; i>=1; i--){
   a[c[i][1]][c[i][2]]='X';
   k--;
   if (k==0) break;
   }          
   }
 
        
   
   for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            cout<<a[i][j];
    cout<<endl;
      
    }




    return 0;
}