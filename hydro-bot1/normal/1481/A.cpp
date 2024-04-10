// Hydro submission #6274cd85bda16328ffbafa09@1651821958032
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,px,py,u,d,l,r,n,i,j;
    cin>>t;
    string s;
    for(i=0;i<t;i++)
    {
        cin>>px>>py>>s;
        n=s.size();
        x=0,y=0,u=0,d=0,l=0,r=0;
        for(j=0;j<n;j++)
        switch(s[j])
        {
            case 85:y++,u++;break;
            case 68:y--,d++;break;
            case 76:x--,l++;break;
            case 82:x++,r++;break;
        }
        printf(y>py&&u<y-py||y<py&&d<py-y||x>px&&r<x-px||x<px&&l<px-x?"NO\n":"YES\n");
    }
    return 0;
}