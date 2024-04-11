#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        int b,p,f;
        cin>>b>>p>>f;
        int h,c;
        cin>>h>>c;
        //a partir daqui posso assumir h>=c
        if(h<c){
            swap(h,c);
            swap(p,f);
        }
        int resp=0;
        while(b>=2&&p>=1){
            b-=2;
            p-=1;
            resp+=h;
        }
        while(b>=2&&f>=1){
            b-=2;
            f-=1;
            resp+=c;
        }
        cout<<resp<<endl;
    }
    
    return 0;
 
}