#include <iostream>
#include <math.h>
#define For(i,i0,i1) for(int i=i0;i<i1;i++)

using namespace std;

bool fr(int y,int f,int ex,int n0)
{
    int a,b,c;
    a=y;
    b=f;
    c=0;
    For(j,0,n0){
   //     cout<<a<<'\t'<<b<<endl;
        if(a%2!=b%2) c++;
        a=(int)(a/2);
        b=(int)(b/2);
    }
   /* cout<<endl;
    cout<<endl;*/
    if(c<=ex) return true;
    return false;
}

int main()
{
    int m,n,k;
    cin>>n>>m>>k;
    int x[2000];
    For(i,0,m+1){
        cin>>x[i];
    }
    int ans=0;
    For(i,0,m){
        if(fr(x[i],x[m],k,n)){
            ans++;
  //         cout<<x[i]<<endl;
        }
    }
    cout<<ans;
 //  cout<<fr(5,17,1,7);
    return 0;
}