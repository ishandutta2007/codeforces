#include <bits/stdc++.h>

using namespace std;
long visina[1000000];
long indeks[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long h,i,z=0,aa=0,j,mark=0;
    cin>>h;
    for(i=0;i<=h;i++){
        cin>>visina[i];
        if(visina[i]>1 && visina[i-1]>1){
            aa=1;
            if(mark==0)mark=i;
        }
    }
    if(aa<1){cout<<"perfect";return 0;}
    cout<<"ambiguous\n";
    cout<<0<<" ";
    indeks[0]=1;
    z=1;
    for(i=1;i<=h;i++){
        for(j=1;j<=visina[i];j++){
            cout<<indeks[i-1]<<" ";
        }
        z+=visina[i];
        indeks[i]=z;
    }
    cout<<endl;
    for(i=1;i<=h;i++)indeks[i]=0;
    cout<<0<<" ";
    z=1;
    indeks[0]=1;
    for(i=1;i<=h;i++){
        if(mark==i){
            cout<<indeks[i-1]-1<<" ";
            for(j=2;j<=visina[i];j++)
            cout<<indeks[i-1]<<" ";
        }
        else for(j=1;j<=visina[i];j++)cout<<indeks[i-1]<<" ";

        z+=visina[i];
        indeks[i]=z;
    }
    return 0;
}