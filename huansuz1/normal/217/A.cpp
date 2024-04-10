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

int a[1234][1234],b[1234][1234];
int n;
queue < pair < int , int > > q;
int x[123],y[123],ans;

int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>x[i]>>y[i];
        a[x[i]][y[i]]=1;
    }
    for (int ii=0; ii<n; ii++)
        if (a[x[ii]][y[ii]]==1) { 
            q.push(mp(x[ii],y[ii]));
            ans++;
            while(!q.empty()){
                int xx=q.front().f;
                int yy=q.front().s;
                b[xx][yy]=1;
                q.pop();
                    for (int i=1; i<=1000; i++){
                        if (a[xx][yy-i]==1 && b[xx][yy-i]==0) {
                            q.push(mp(xx,yy-i)); 
                            a[xx][yy-i]=a[xx][yy]+1; 
                            b[xx][yy-i]=1;
                            break;
                        }
                        if (b[xx][yy-i]!=0) break;
                        if (yy-i<0) break;
                    }
                    for (int i=1; i<=1000; i++){
                        if (a[xx][yy+i]==1 && b[xx][yy+i]==0) {
                            q.push(mp(xx,yy+i)); 
                            a[xx][yy+i]=a[xx][yy]+1; 
                            b[xx][yy+i]=1;
                            break;
                        }
                        if (b[xx][yy+i]!=0) break;
                        if ( yy+i>1000) break;
                    }
                    for (int i=1; i<=1000; i++){
                        if (a[xx+i][yy]==1 && b[xx+i][yy]==0) {
                            q.push(mp(xx+i,yy)); 
                            a[xx+i][yy]=a[xx][yy]+1; 
                            b[xx+i][yy]=1;
                            break;
                        }
                        if (b[xx+i][yy]!=0) break;
                        if (xx+i>1000 ) break;
                    }
                    for (int i=1; i<=1000; i++){
                        if (a[xx-i][yy]==1 && b[xx-i][yy]==0) {
                            q.push(mp(xx-i,yy)); 
                            a[xx-i][yy]=a[xx][yy]+1; 
                            b[xx-i][yy]=1;
                            break;
                        }
                        if (b[xx-i][yy]!=0) break;
                        if (xx-i<0 ) break;
                    }           
            }
        }
     
    
    if (ans==0) cout<<0; else
    cout<<ans-1;
    
      

    return 0;
}