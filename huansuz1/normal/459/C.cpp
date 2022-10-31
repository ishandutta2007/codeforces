#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#define ll long long
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define MAXN (1 << 20)


using namespace std;

int n,k,d,ans[1234][1234],r,c[1234],u,w[1234];

int main(){
    cin>>n>>k>>d;
if(k<n){
        if(d>1&&k*k<n){
            ll cur=1ll;
            bool  ok=0;
            for(int i=0; i<d; i++)
                if(cur*k>=n){
                    ok=1;
                    break;
                }
                else
                    cur*=k*1ll;
            if(!ok){
                cout<<"-1";
                return 0;
            }
        }   
        if(d==1){
            cout<<"-1";
            return 0;
        }
    }   
    for(int i=0; i<n; i++){
        int m=i,l=0;
        while(m){
            ans[i][l++]=m%k;
            m/=k;
        }
    }
        
    for(int i=0; i<d; i++){
    for(int j=0; j<n; j++)  
        printf("%d ", ans[j][i]+1);
        printf("\n");
    } 






    return 0;
}