#include <bits/stdc++.h>

using namespace std;
queue <long> kju;
int main()
{
    long r,x,b,k,br=0;
    cin>>x;
    while(x!=0){
        r=x;
        b=0;
        k=0;
        while(r>0){
            if(r%10!=0)b+=pow(10,k);
            r/=10;
            k++;
        }
        br++;
        kju.push(b);
        x-=b;
    }
    cout<<br<<endl;
    while(!kju.empty()){
        cout<<kju.front()<<" ";
        kju.pop();
    }
    return 0;
}