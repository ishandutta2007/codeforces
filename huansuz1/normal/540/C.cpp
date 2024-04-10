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


queue < pair < int , int > > q;
int n,m,x,y,xx,yy,i,j;
char ar[1234][1234];
                       
int main(){
    cin>>n>>m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            cin>>ar[i][j];
    cin>>x>>y;
    cin>>xx>>yy;
    q.push(mp(x,y));

   while(!q.empty()){
        i=q.front().f;
        j=q.front().s;
        q.pop();
        ar[i][j]='X'; 
        if (i+1==xx && j==yy && ar[i+1][j]=='X') { cout<<"YES"; exit(0); }
        if (i-1==xx && j==yy && ar[i-1][j]=='X') { cout<<"YES"; exit(0); }
        if (i==xx && j+1==yy && ar[i][j+1]=='X') { cout<<"YES"; exit(0); }
        if (i==xx && j-1==yy && ar[i][j-1]=='X') { cout<<"YES"; exit(0); } 
        if (ar[i+1][j]=='.') {q.push(mp(i+1,j)); ar[i+1][j]='X';}
        if (ar[i-1][j]=='.') {q.push(mp(i-1,j)); ar[i-1][j]='X';}
        if (ar[i][j-1]=='.') {q.push(mp(i,j-1)); ar[i][j-1]='X';}
        if (ar[i][j+1]=='.') {q.push(mp(i,j+1)); ar[i][j+1]='X';}
         
    }
    cout<<"NO";


    
    





}