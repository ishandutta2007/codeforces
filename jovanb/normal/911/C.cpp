#include <bits/stdc++.h>

using namespace std;
int pokusaj(int a,int b,int c){
    long pocb,pocc,mozeovo,i,k;
    for(i=1;i<=a;i++){
        pocb=0;
        pocc=0;
        for(k=i;k<=100;k++){
            mozeovo=0;
            if((k-i)%a==0)mozeovo=1;
            if(mozeovo==0 && pocb==0)pocb=k;
            if(pocb>0 && (k-pocb)%b==0)mozeovo=1;
            if(mozeovo==0 && pocc==0)pocc=k;
            if(pocc>0 && (k-pocc)%c==0)mozeovo=1;
            if(mozeovo==0)return 0;
            if(k==100){return 1;}
        }

    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long x,y,z;
    cin>>x>>y>>z;
    if(pokusaj(x,y,z)==1 || pokusaj(x,z,y)==1 || pokusaj(y,x,z)==1 || pokusaj(y,z,x)==1 || pokusaj(z,x,y)==1 || pokusaj(z,y,x)==1){cout<<"YES";return 0;}
    cout<<"NO";
    return 0;
}