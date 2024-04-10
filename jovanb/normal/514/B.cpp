#include <bits/stdc++.h>

using namespace std;
bool tooch[10000];
int x1[10000],y1[10000];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,x,y,br=0,i,j ;
    cin>>n>>x>>y;
    for(i=0;i<n;i++)cin>>x1[i]>>y1[i];
    for(i=0;i<n;i++){
        if(!tooch[i]){
            br++;
            tooch[i]=true;
            for(j=0;j<n;j++){
                if((x1[i]-x)*(y1[j]-y)==(x1[j]-x)*(y1[i]-y))tooch[j]=1;
            }
        }
    }
    cout<<br;
    return 0;
}