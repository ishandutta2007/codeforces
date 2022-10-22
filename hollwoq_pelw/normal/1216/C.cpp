#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    cin>>x5>>y5>>x6>>y6;

    if(x3<=x1&&y3<=y1&&x4>=x2&&y4>=y2)return printf("NO"),0;

    if(x5<=x1&&y5<=y1&&x6>=x2&&y6>=y2)return printf("NO"),0;

    if(x3<=x1&&x5<=x1 && x4>=x2&&x6>=x2 )
    {
        if(y5<=y1&&y4>=y2&&y6>=y3)return printf("NO"),0;

        if(y3<=y1&&y6>=y2&&y4>=y5)return printf("NO"),0;
    }

    if(y3<=y1&&y5<=y1 && y4>=y2&&y6>=y2 )
    {
        if(x3<=x1&&x6>=x2&&x4>=x5 )return printf("NO"),0;
        if(x5<=x1&&x4>=x2&&x6>=x3)return printf("NO"),0;
    }

    cout<<"YES";

    return 0;
}