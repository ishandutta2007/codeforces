#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int n,m,k,z,a[321][321],p,t=1;


int main()
{
    cin>>n>>m>>k;      
    if (k>1){
        cout<<2<<" ";   
        for (int i=1; i<=n; i++){
            if (i%2) {
                for (int j=1; j<=m; j++){
                    z++;
                    cout<<i<<" "<<j<<" ";   
                    a[i][j]=1;
                    if (z==(k-1)*2){p=1; break;}
                    if (z%2==0) cout<<endl<<2<<" "; 
                }
                if (p) break;
            } else {
                for (int j=m; j>=1; j--){
                    z++;
                    a[i][j]=1;
                    cout<<i<<" "<<j<<" ";   
                    if (z==(k-1)*2){p=1; break;}
                    if (z%2==0) cout<<endl<<2<<" "; 
                }
                if (p) break;
            }
        }
        cout<<endl<<(n*m)-z<<" ";
        for (int i=1; i<=n; i++){
            if (i%2){
                for (int j=1; j<=m; j++)
                    if (a[i][j]==0) cout<<i<<" "<<j<<" ";
            } else {
                for (int j=m; j>=1; j--)
                    if (a[i][j]==0) cout<<i<<" "<<j<<" ";
            }
    
        }     
    } else {
        cout<<n*m<<" ";
        for (int i=1; i<=n; i++){
            if (i%2){
                for (int j=1; j<=m; j++)
                    if (a[i][j]==0) cout<<i<<" "<<j<<" ";
            } else {
                for (int j=m; j>=1; j--)
                    if (a[i][j]==0) cout<<i<<" "<<j<<" ";
            }
    
        }
    
    }
    return 0;
}