#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a=1,b=1,c=0,n,x,i,res=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        if(x==1){
            if(a==0)res=1;
            else if(b==0){b=1;c=0;}
            else {b=0;c=1;}
        }
        if(x==2){
            if(b==0)res=1;
            else if(a==0){a=1;c=0;}
            else {c=1;a=0;}
        }
        if(x==3){
            if(c==0)res=1;
            else if(a==0){a=1;b=0;}
            else {a=0;b=1;}
        }
    }
    if(res==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}