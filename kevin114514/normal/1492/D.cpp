#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,k;
    cin>>a>>b>>k;
    if(!k)
    {
        puts("Yes");
        for(int i=0;i<b;i++)
            cout<<"1";
        for(int i=0;i<a;i++)
            cout<<"0";
        puts("");
        for(int i=0;i<b;i++)
            cout<<"1";
        for(int i=0;i<a;i++)
            cout<<"0";
        puts("");
        return 0;
    }
    if(k>a+b-2||b<2||a<1)
        puts("No");
    else
    {
        puts("Yes");
        a--;
        b-=2;
        k--;
        int m1=min(k,a);
        k-=m1;
        int m2=min(k,b);
        a-=m1;
        b-=m2;
        cout<<"11";
        for(int i=0;i<m1;i++)
            cout<<"0";
        for(int i=0;i<m2;i++)
            cout<<"1";
        cout<<"0";
        for(int i=0;i<a;i++)
            cout<<"0";
        for(int i=0;i<b;i++)
            cout<<"1";
        puts("");
        cout<<"10";
        for(int i=0;i<m1;i++)
            cout<<"0";
        for(int i=0;i<m2;i++)
            cout<<"1";
        cout<<"1";
        for(int i=0;i<a;i++)
            cout<<"0";
        for(int i=0;i<b;i++)
            cout<<"1";
        puts("");
    }
    return 0;
}