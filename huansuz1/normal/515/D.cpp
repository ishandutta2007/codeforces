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
char a[2123][2123];
int n,m;
void check(int i,int j){
			if (a[i][j]=='.' && a[i][j+1]=='.' && a[i][j-1]!='.' && a[i+1][j]!='.' && a[i-1][j]!='.') q.push(mp(i,j));
        	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]=='.' && a[i+1][j]!='.' && a[i-1][j]!='.') q.push(mp(i,j));
        	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]!='.' && a[i+1][j]=='.' && a[i-1][j]!='.') q.push(mp(i,j));
        	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]!='.' && a[i+1][j]!='.' && a[i-1][j]=='.') q.push(mp(i,j));


}
                       
int main(){
    scanf("%d%d\n",&n,&m);
    n++;
    m++;
    for (int i=2; i<=n; i++) {
    		scanf("%s\n",a[i] + 2);
    	}
   	
   	for (int i=2; i<=n; i++)
    	for (int j=2; j<=m; j++){
    		if (a[i][j]=='.' && a[i][j+1]=='.' && a[i][j-1]!='.' && a[i+1][j]!='.' && a[i-1][j]!='.') q.push(mp(i,j));
        	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]=='.' && a[i+1][j]!='.' && a[i-1][j]!='.') q.push(mp(i,j));
        	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]!='.' && a[i+1][j]=='.' && a[i-1][j]!='.') q.push(mp(i,j));
        	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]!='.' && a[i+1][j]!='.' && a[i-1][j]=='.') q.push(mp(i,j));
        }
    while(!q.empty()){
    	int i=q.front().f;
    	int j=q.front().s;
    	q.pop();
    	if (a[i][j]=='.' && a[i][j+1]=='.' && a[i][j-1]!='.' && a[i+1][j]!='.' && a[i-1][j]!='.') { a[i][j]='<'; a[i][j+1]='>'; check(i,j+2); check(i-1,j+1);check(i+1,j+1);}
    	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]=='.' && a[i+1][j]!='.' && a[i-1][j]!='.') { a[i][j]='>'; a[i][j-1]='<'; check(i,j-2); check(i-1,j-1);check(i+1,j-1);}
    	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]!='.' && a[i+1][j]=='.' && a[i-1][j]!='.') { a[i][j]='^'; a[i+1][j]='v'; check(i+2,j); check(i+1,j+1);check(i+1,j-1);}
    	if (a[i][j]=='.' && a[i][j+1]!='.' && a[i][j-1]!='.' && a[i+1][j]!='.' && a[i-1][j]=='.') { a[i][j]='v'; a[i-1][j]='^'; check(i-2,j); check(i-1,j+1);check(i-1,j-1);}    
    }
     for (int i=2; i<=n; i++)
    	for (int j=2; j<=m; j++)
   			if (a[i][j]=='.') {cout<<"Not unique"; exit(0); }
   	  for (int i=2; i<=n; i++)   {
    		printf("%s\n",a[i]+2);
    }
    			
    	

}