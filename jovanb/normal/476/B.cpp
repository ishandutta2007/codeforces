#include <bits/stdc++.h>

using namespace std;
char ch[200];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,i;
    cin>>ch;
    n=strlen(ch);
    long x=0,y=0,bru=0;
    double k=1;
    for(i=0;i<n;i++){
        if(ch[i]=='+')x++;
        else x--;
    }
    cin>>ch;
    for(i=0;i<n;i++){
        if(ch[i]=='+')y++;
        else if(ch[i]=='-')y--;
        else bru++;
    }
    x-=y;
    if(bru%2!=abs(x)%2){cout<<0;return 0;}
    if(bru-x<0 || bru+x<0){cout<<0;return 0;}
    for(i=0;i<(bru+x)/2;i++){
        k*=bru-i;
        k/=i+1;
    }
    k/=pow(2,bru);
    cout<<fixed<<setprecision(10)<<k;
    return 0;
}