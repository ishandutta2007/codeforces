#include <iostream>

using namespace std;

int main()
{
    long a,b,f,k,brojac=0,i=0,cb;
    cin>>a>>b>>f>>k;
    cb=b;
    while(i<k){
        if(cb<f){cout<<-1;return 0;}
        cb-=f;
        if(cb<2*(a-f)){ if(i<k-1){cb=b;brojac++;}
            else if(cb<a-f){cb=b;brojac++;}}
        if(cb<a-f){cout<<-1;return 0;}
        i++;
        cb-=(a-f);
        if(i==k){cout<<brojac;return 0;}
        if(cb<a-f){cout<<-1;return 0;}
        cb-=(a-f);
        if(cb<2*f){
            if(i<k-1){cb=b;brojac++;}
            else if(cb<f){cb=b;brojac++;}
        }
        cb-=f;
        i++;
        if(i==k){cout<<brojac;return 0;}


    }
    cout<<brojac<<endl;
    return 0;
}