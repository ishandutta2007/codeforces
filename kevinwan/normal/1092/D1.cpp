#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,num=0,pen=0,ln=-1;
    scanf("%d",&n);
    int cur=0,x;
    for(int i=0;i<=n;i++){
        if(i!=n)scanf("%d",&x);
        else x++;
        x&=1;
        if(x==cur)num++;
        else{
            if(num&1){
                if(x==ln)pen--,ln=1-ln;
                else pen++,ln=x;
                if(pen==0)ln=-1;
            }
            num=1;
            cur=x;
        }
    }
    if(pen<=1)printf("YES");
    else printf("NO");
}