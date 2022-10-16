#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mp make_pair

int nwd(int a, int b)
{
    while (b!=0)
    {
        int c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int k;
    cin>>n>>k;
    int x=k;
    for (int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        x=nwd(x,a);
    }

    int w=k/x;


    cout <<w<<endl;

    for (int i=0; i<w; i++)
        cout <<i*x<<" ";
    cout <<endl;

}