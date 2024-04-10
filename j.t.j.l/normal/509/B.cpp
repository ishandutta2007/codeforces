#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int n,k,p,q,a[200],i,j;

int main(){
    cin>>n>>k;
    p=1000;
    q=0;
    rep(i,1,n){
        scanf("%d",&a[i]);
        if (a[i]>q)
            q=a[i];
        if (a[i]<p)
            p=a[i];
    }
    if (q-p>k)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        rep(i,1,n){
            if (a[i]==p){
                rep(j,1,p-1)
                    printf("1 ");
                cout<<1<<endl;
            }
            else{
                rep(j,1,p)
                    printf("1 ");
                rep(j,p+1,a[i]-1)
                    printf("%d ",j-p);
                cout<<a[i]-p<<endl;
            }
        }
    }
    return 0;
}