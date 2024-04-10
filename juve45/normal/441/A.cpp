#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
vector <int> vv;

int n, v, a, k;

int main()
{
cin>>n>>v;
int ok;
for(int i=1;i<=n;i++)
{
        cin>>k;
        ok=0;
for(int j=1;j<=k;j++)
{
    cin>>a;
        if(a<v && ok==0)
        {
            vv.pb(i);
            ok=1;
        }
}

}
cout<<vv.size()<<'\n';
for(int i=0;i<vv.size();i++)
    cout<<vv[i]<<' ';

    return 0;
}