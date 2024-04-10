#include<bits/stdc++.h>
using namespace std;
int cnt;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string S;
        cin>>S;
        if(S=="Tetrahedron")
            cnt+=4;
        if(S=="Cube")
            cnt+=6;
        if(S=="Octahedron")
            cnt+=8;
        if(S=="Dodecahedron")
            cnt+=12;
        if(S=="Icosahedron")
            cnt+=20;
    }
    cout<<cnt<<endl;
    return 0;
}