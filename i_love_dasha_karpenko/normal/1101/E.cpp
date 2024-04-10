#include <bits/stdc++.h>

using namespace std;
#define DIM 100000007
typedef pair<long long,long long> pairll;
long long maxx=-DIM,miny=-DIM,x,y,n;
char p;

int main()
{
   // freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int h = 0;h<n;h++){
        cin>>p;
        cin>>x>>y;

        if (p=='+'){
            if (x>miny && y>miny){miny=min(x,y);}
        if (x>maxx){maxx=x;}
        if (y>maxx){maxx=y;}
        }
        else{

            if ( (maxx<=x || maxx<=y) && (miny<=x && miny<=y) )cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

}