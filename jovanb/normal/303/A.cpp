#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,i;
    cin>>n;
    if(n%2==0){cout<<-1;return 0;}
    else{
        for(i=0;i<n;i++)cout<<i<<" ";
        cout<<endl;
        for(i=0;i<n;i++)cout<<i<<" ";
        cout<<endl;
        for(i=0;i<n;i++)cout<<(2*i)%n<<" ";
    }
    return 0;
}