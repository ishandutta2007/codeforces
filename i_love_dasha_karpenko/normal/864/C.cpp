#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
long long a,b,f,k,dist0,dista,curb,pos,laps = 0,res = 0,maxb;
int main()
{
    cin>>a>>b>>f>>k;
    curb = b;
    maxb = b;
    pos = 0;
    long long cof;
    while(laps<k){

        if (laps+1==k && b>=a)break;
        if (pos==0){
            if (b>=a+a-f){b-=a;}
            else if (b<f){
                cout<<-1<<endl;
                return 0;
            }
            else{
                b = maxb-a+f;
                if (b<0){
                    cout<<-1<<endl;
                    return 0;
                }
                res++;
            }
        }
        else{
            if (b>=a+f){b-=a;}
            else if (b<a-f){
                cout<<-1<<endl;
                return 0;
            }
            else{
                b = maxb-f;
                res++;
                if (b<0){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        laps++;
        pos^=1;
    }
    cout<<res<<endl;
}