#include<iostream>
using namespace std;
int n,m,k;
int main()
{
    cin>>n>>k;
    if (n/2>k){
        cout<<-1<<endl; return 0;
    }
    if (n==1){
        if (k!=0) cout<<-1<<endl; else cout<<1<<endl;
        return 0;
    }
    int k1=k-(n/2-1); int k2=k1*2,k3=0;
    for (int i=1;i<=n/2-1;i++)
    {
        k3++; 
        for (;k3==k1||k3==k2||k3+1==k1||k3+1==k2;k3++);
        cout<<k3<<" "<<k3+1<<" ";
        k3++;
    }
    cout<<k1<<" "<<k2;
    if (n%2) {
        k3++;
        if (k3==k1||k3==k2) k3++;
        if (k3==k1||k3==k2) k3++;
        cout<<" "<<k3<<endl; 
    }else  cout<<endl;
    return 0;
}