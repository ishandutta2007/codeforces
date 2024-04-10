#include <bits/stdc++.h>

using namespace std;
int exists[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int y,x,i;
    cin>>y;
    i=y;
    while(1){
        i++;
        x=i;
        while(x>0){
            if(exists[x%10]>0)break;
            exists[x%10]++;
            x/=10;
            if(x==0){cout<<i;return 0;}
        }
        for(x=0;x<10;x++)exists[x]=0;
    }
    return 0;
}