#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int a[4000010];
long long cnt[4000010];

int main()
{
    int n, m;
    cin >> n >> m;
    if (m<=(n+1)*2 && n<=m+1) {
        if (n<m) {
            while(m-n>=2 && n!=0){
                printf("%d%d",1,1);
                m-=2;
                printf("%d",0);
                n--;
            }
            while(m!=0 && n!=0){
                printf("%d",1);
                m--;
                printf("%d",0);
                n--;                
            } 
            if (m==2) cout<<11; else 
                if (m==1) cout<<1;
            if (n==1)  cout<<0;
        
        } else {
            while(n!=0 && m!=0){
                printf("%d",0);
                n--;
                printf("%d",1);
                m--;                
            }
            if (n==1) cout<<0;
            if (m==2) cout<<11; else 
                if (m==1) cout<<1;
        
        }
        return 0;
    
    }
    cout<<-1;
    return 0;
}