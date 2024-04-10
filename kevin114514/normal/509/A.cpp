#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    long long Ans=1;
    N--;
    for(int i=N*2;i>N;i--)
        Ans*=i;
    for(int i=1;i<=N;i++)
        Ans/=i;
    cout<<Ans<<endl;
    return 0;
}