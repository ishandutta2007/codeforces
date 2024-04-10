#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,c,d;
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        if(a>c)swap(a,c);
        if(b>c)swap(b,c);
        cout<<abs(c-a-b)+1<<endl;
    }
}