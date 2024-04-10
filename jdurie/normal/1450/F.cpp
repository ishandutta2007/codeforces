#include<bits/stdc++.h>
using namespace std;
#define F(l,r) for(int i=l;i<r;++i)
#define N 100010
int t,n,a[N],c[N];
int main(){
    cin>>t;while(t--){
        cin>>n;F(0,n)cin>>a[i],c[a[i]]++;
        if(*max_element(c,c+n+1)>(n+1)/2)cout<<"-1\n";
        else{
            int x=1;
            fill_n(c,n+1,0);
            c[a[0]]++,c[a[n-1]]++;
            F(0,n-1)if(a[i]==a[i+1])c[a[i]]+=2,x++;
            int z=x-1;
            F(1,n+1)z+=max(0,c[i]-1-x);
            cout<<z<<'\n';
        }
        fill_n(c,n+1,0);
    }
}