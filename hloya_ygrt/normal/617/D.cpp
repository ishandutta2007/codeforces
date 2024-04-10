#include <bits\stdc++.h>

using namespace std;
#define mp make_pair
#define f first
#define pb push_back
#define ll long long
#define s second

const int eps=1e-8,maxn=1e5;

int main()
{
    int x1,x2,y1,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    if (x1==x2&&x2==x3){
        cout<<1;
        return 0;
    }

    if (y1==y2&&y2==y3){
        cout<<1;
        return 0;
    }
//|-.
//.
//|
//.
//
    if (y2>y1&&x2==x1&&(y3>=y2||y3<=y1)){
        cout<<2;
        return 0;
    }


    if (y1>y2&&x2==x1&&(y3<=y2||y3>=y1)){
        cout<<2;
        return 0;
    }


    if (y3<y1&&x3==x1&&(y2>=y1||y2<=y3)){
        cout<<2;
        return 0;
    }
       
   if (y3>y1&&x3==x1&&(y2<=y1||y2>=y3)){
        cout<<2;
        return 0;
    }

    if (y2>y3&&x2==x3&&(y2<=y1||y1<=y3)){
        cout<<2;
        return 0;
    }


    if (y2<y3&&x2==x3&&(y1>=y3||y1<=y2)){
        cout<<2;
        return 0;
    }
    
//|.---.
//|
//.
    if (x2>x1&&y2==y1&&(x3>=x2||x3<=x1)){
        cout<<2;
        return 0;
    }


    if (x1>x2&&y2==y1&&(x3<=x2||x3>=x1)){
        cout<<2;
        return 0;
    }


    if (x3<x1&&y3==y1&&(x2>=x1||x2<=x3)){
        cout<<2;
        return 0;
    }

   if (x3>x1&&y3==y1&&(x2<=x1||x2>=x3)){
        cout<<2;
        return 0;
    }

    if (x2>x3&&y2==y3&&(x2<=x1||x1<=x3)){
        cout<<2;
        return 0;
    }


    if (x2<x3&&y2==y3&&(x2>=x1||x1>=x3)){
        cout<<2;
        return 0;
    }


    cout<<3;
    return 0;
}