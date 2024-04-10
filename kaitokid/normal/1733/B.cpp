#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        if(x>y)swap(x,y);
        if((x!=0)||(y==0)){cout<<-1<<endl;continue;}
        if(((n-1)%y)!=0){cout<<-1<<endl;continue;}
        for(int i=0;i<n-1;i++)
        {
            int d=(i-(i%y));
            cout<<2+d<<" ";
        }
        cout<<endl;

    }
    return 0;
}