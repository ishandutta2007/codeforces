#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int n, exit[1000010], enter[1000010];
int main()
{
    cin>>n;
    char c;
    for(int i=1;i<=n;i++)
    {
        int sgn=1, a;
        cin>>c;

        cin.get();
        cin>>a;
        if(c=='-')
            sgn=-1, exit[a]=1;
            else
            if( exit[a]!=1 )
                enter[a]=1;
        v.push_back(sgn);
    }
    int start=0;

    for(int i=1;i<=1000000;i++)
        if(exit[i]==1 && enter[i]==0)
        start++;

    int current=start;
    int maxcurrent=current;
    for(int i=0;i<n;i++)
    {
        current+=v[i];
        if(current>maxcurrent)
            maxcurrent=current;
    }
    cout<<maxcurrent<<'\n';

    return 0;
}