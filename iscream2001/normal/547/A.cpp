#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=1e5+10;

void init(){
	
}
const int E=400;
void MAIN(){
	ll m;
    while(scanf("%I64d",&m)!=EOF)
    {
        ll h1,a1,x1,y1,h2,a2,x2,y2;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
        ll xun1=0,xun2=0,num1=0,num2=0;
        ll h;
        h=h1;
//        cout<<"h11111111"<<h<<"  "<<a1<<endl;
        for(ll i=1;i<=2*m;i++)
        {
            h=(x1*h+y1)%m;
//            cout<<"h1111111"<<h<<endl;
            if(h==a1)
            {
                if(num1==0)
                {
                    num1=i;
                }
                else if(xun1==0)
                {
                    xun1=i-num1;
                    break;
                }
            }
        }
        h=h2;
        for(ll i=1;i<=2*m;i++)
        {
            h=(x2*h+y2)%m;
//            cout<<"ii "<<i<<"hh "<<h<<endl;
            if(h==a2)
            {
                if(num2==0)
                {
                    num2=i;
                }
                else if(xun2==0)
                {
                    xun2=i-num2;
//                    cout<<"i "<<i<<endl;
                }
            }
        }
//        cout<<"num "<<num1<<"  "<<num2<<endl;
//        cout<<"xun "<<xun1<<"  "<<xun2<<endl;
        if(num1==0||num2==0)
        {
            puts("-1");
            continue;
        }
        else
        {
            ll flag=0;
            for(ll i=0;i<=m;i++)
            {
                if(xun2==0)//a2
                {
                    if(num1+i*xun1==num2)
                    {
                        printf("%I64d\n",num1+i*xun1);
                        flag=1;
                        break;
                    }
                }
                else
                {
                    if(num1+i*xun1>=num2&&(num1+i*xun1-num2)%xun2==0)
                    {
                        printf("%I64d\n",num1+i*xun1);
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag)
                puts("-1");
        }
    }
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}