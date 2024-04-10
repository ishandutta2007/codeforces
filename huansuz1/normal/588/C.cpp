#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 

using namespace std;

int a[123456],n,x,y,m,ans,b[2253455];

int main(){
    scanf("%d",&n);

    for (int i=0; i<n; i++){  
        scanf("%d",&x);          
        b[x]++;
    }
    for (int i=0; i<=2000000; i++){
        b[i+1]+=b[i]/2;
        if (b[i]%2==1) ans++;
    }
    cout<<ans;



    return 0;
}