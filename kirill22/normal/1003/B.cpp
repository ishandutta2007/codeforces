#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b , x;
    cin >> a >> b >> x;
    int b1=b,a1=a;
    bool flag=true;
    string s="";
    if (a>=b){
        for (int i=0;i<a+b;++i){
            if (x==1){
                break;
            }
            else if(i%2==0){
                s=s+"0";
                a1--;
                flag=true;
            }
            else {
                s=s+"1";
                b1--;
                flag=false;

            }
            --x;
            if (i==0){
                ++x;
            }


        }
        if (flag){
            while (a1>0){
                    s=s+"0";
                    --a1;
            }
            while (b1>0){
                    s=s+"1";
                    --b1;
                    }
        }
        else{
            while (b1>0){
                    s=s+"1";
                    --b1;
            }
            while (a1>0){
                    s=s+"0";
                    --a1;
            }
        }
    }
    else{
        for (int i=0;i<a+b;++i){
            if (x==1){
                break;
            }
            else if(i%2==0){
                s=s+"1";
                b1--;
                flag=true;
            }
            else {
                s=s+"0";
                a1--;
                flag=false;

            }
            --x;
            if (i==0){
                ++x;
            }


        }
        if (! flag){
            while (a1>0){
                    s=s+"0";
                    --a1;
            }
            while (b1>0){
                    s=s+"1";
                    --b1;
                    }
        }
        else{
            while (b1>0){
                    s=s+"1";
                    --b1;
            }
            while (a1>0){
                    s=s+"0";
                    --a1;
            }
        }
    }

    cout << s;

}