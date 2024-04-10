#include <iostream>
#include<algorithm>

using namespace std;

long long a[10][10],b[10],MAX,ans;

int main()
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    for(int i=0;i<5;i++)
        b[i]=i+1;
    do{
        ans=0;
        for(int i=0;i<4;i++)
            for(int j=i;j<4;j+=2)
                ans+=a[b[j]][b[j+1]]+a[b[j+1]][b[j]];
        MAX=max(MAX,ans);
    }while(next_permutation(b,b+5));
    cout<<MAX<<endl;
}