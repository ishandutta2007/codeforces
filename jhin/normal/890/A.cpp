#include<bits/stdc++.h>

using namespace std;
int sum1,sum2,a[6];

int main(){

    for(int i=0;i<6;i++){cin>>a[i];sum1+=a[i];}
    sort(a,a+6);
    for(int i=0;i<6;i++)for(int j=i+1;j<6;j++)
    for(int z=j+1;z<6;z++){sum2=a[i]+a[j]+a[z];if(sum2==sum1-sum2)
    return cout<<"YES",0;}
     cout<<"NO";





    return 0;
}