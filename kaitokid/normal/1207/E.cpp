#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q=1<<7;
    cout<<"? ";
    for(int i=q;i<q+q*100;i+=q){cout<<i<<" ";}
    cout<<endl;
    fflush(stdout);
    int x,y;
    cin>>x;
//x=343^256;
    cout<<"? ";
    for(int i=0;i<100;i++){cout<<i<<" ";}
    cout<<endl;
    fflush(stdout);
    //y=343^5;
    cin>>y;
    x%=q;
    y=y>>7;
    y=y<<7;
    cout<<"! "<<(x+y);
    cout<<endl;
    fflush(stdout);

    return 0;
}