#include <iostream>
#include<algorithm>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;
int n,MAX;
pii p[10000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].X>>p[i].Y;
    sort(p,p+n);
    MAX=p[0].Y;
    for(int i=1;i<n;i++)
    {
        if(p[i].Y>=MAX)
            MAX=p[i].Y;
        else
            MAX=p[i].X;
    }
    cout<<MAX<<endl;
}